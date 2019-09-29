#include "./mstore_client.h"

#include "hiredis/adapters/libuv.h"
#include "hiredis/async.h"
#include "hiredis/hiredis.h"

namespace rmsg {
namespace mstore {

struct RedisCommand {
  std::string str;
  std::function<void(const std::shared_ptr<Result>)> on_reply_cb;
};

// Todo: Reconnectとかエラー周りの実装,ステート管理
class Client::ClientImpl {
 public:
  ClientImpl(std::string host, int port, uv_loop_t* uv_loop)
      : host(host),
        port(port),
        uv_loop(uv_loop),
        _ctx(nullptr),
        conn_state(ConnState::InitialState) {}

  enum class ConnState {
    InitialState,
    Connecting,
    Connected,
    Disconnected,
  };

  void Connect() {
    if (conn_state == ConnState::Connecting) {
      return;
    }
    SetState(ConnState::Connecting);
    _ctx = redisAsyncConnect(host.c_str(), port);
    _ctx->data = this;
    if (redisLibuvAttach(_ctx, uv_loop) != REDIS_OK) {
      SetState(ConnState::Disconnected);
      Reconnect();
      return;
    }

    redisAsyncSetConnectCallback(_ctx, OnConnected);
    redisAsyncSetDisconnectCallback(_ctx, OnDisconnected);
  }

  void Reconnect() {
    // 将来的にConnectと動作を変えるかもしれないので一応メソッドは分けておく
    if (conn_state == ConnState::Connecting) {
      return;
    }
    Connect();
  }

  void SetState(ConnState state) { conn_state = state; }
  ConnState GetState() { return conn_state; }

  static void OnConnected(const redisAsyncContext* ctx, int status) {
    Client::ClientImpl* impl = static_cast<Client::ClientImpl*>(ctx->data);
    if (status == REDIS_OK) {
      impl->SetState(Client::ClientImpl::ConnState::Connected);
    } else {
      impl->SetState(Client::ClientImpl::ConnState::Disconnected);
      impl->Reconnect();
    }
  }

  static void OnDisconnected(const redisAsyncContext* ctx, int status) {
    Client::ClientImpl* impl = static_cast<Client::ClientImpl*>(ctx->data);
    if (status == REDIS_OK) {
      impl->SetState(Client::ClientImpl::ConnState::InitialState);
    } else {
      impl->SetState(Client::ClientImpl::ConnState::Disconnected);
      impl->Reconnect();
    }
  }

  static void OnRedisReplied(redisAsyncContext* ctx, void* r, void* privdata) {
    redisReply* reply = reinterpret_cast<redisReply*>(r);
    auto result = std::make_shared<Result>();
    if (reply) {
      result->ok = true;
      result->value = std::string(reply->str);
    } else {
      result->ok = false;
    }
    RedisCommand* command = reinterpret_cast<RedisCommand*>(privdata);
    command->on_reply_cb(result);
    delete command;
  }

  void AsyncCommand(RedisCommand* command) {
    int status = redisAsyncCommand(_ctx, OnRedisReplied, (void*)command,
                                   command->str.c_str());
    if (status != REDIS_OK) {
      auto result = std::make_shared<Result>();
      result->ok = false;
      command->on_reply_cb(result);
      delete command;
    }
  }

  void Disconnect() { redisAsyncDisconnect(_ctx); }

 private:
  std::string host;
  int port;
  uv_loop_t* uv_loop;
  redisAsyncContext* _ctx;
  ConnState conn_state;
};

Client::Client(std::string host, int port, uv_loop_t* uv_loop)
    : impl(std::make_unique<Client::ClientImpl>(host, port, uv_loop)) {
  impl->Connect();
}

Client::~Client() { impl->Disconnect(); }

void Client::GetValue(
    const std::string& key,
    std::function<void(const std::shared_ptr<Result>)> on_get_value) {
  std::string cmd_str = "GET " + key;
  auto command = new RedisCommand{cmd_str, on_get_value};
  impl->AsyncCommand(command);
}

void Client::SetValue(
    const std::string& key, const std::string& value,
    std::function<void(const std::shared_ptr<Result>)> on_set_value) {
  std::string cmd_str = "SET " + key + " " + value;
  auto command = new RedisCommand{cmd_str, on_set_value};
  impl->AsyncCommand(command);
}

void Client::DeleteValue(
    const std::string& key,
    std::function<void(const std::shared_ptr<Result>)> on_delete_value) {
  std::string cmd_str = "DEL " + key;
  auto command = new RedisCommand{cmd_str, on_delete_value};
  impl->AsyncCommand(command);
}

}  // namespace mstore
}  // namespace rmsg
