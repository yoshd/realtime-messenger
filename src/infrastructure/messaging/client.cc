#include "./client.h"

#include "nats.c/src/adapters/libuv.h"
#include "nats.c/src/nats.h"

namespace rmsg {
namespace infrastructure {
namespace messaging {

class Client::ClientImpl {
 public:
  ClientImpl(std::string host, int port, uv_loop_t* uv_loop)
      : host(host), port(port), uv_loop(uv_loop), nc(nullptr) {}

  void Connect() {
    natsLibuv_Init();
    natsLibuv_SetThreadLocalLoop(uv_loop);
    natsOptions* opts = nullptr;
    auto status = natsOptions_SetEventLoop(opts, (void*)uv_loop,
                                           natsLibuv_Attach, natsLibuv_Read,
                                           natsLibuv_Write, natsLibuv_Detach);

    if (status == NATS_OK) {
      status = natsConnection_Connect(&nc, opts);
    }
  }

  bool Publish(const std::string& subject, const std::string& message) {
    auto status =
        natsConnection_PublishString(nc, subject.c_str(), message.c_str());
    return status == NATS_OK;
  }

  static void onMsg(natsConnection* nc, natsSubscription* sub, natsMsg* msg,
                    void* closure) {
    auto msg_str =
        std::string(natsMsg_GetData(msg), natsMsg_GetDataLength(msg));
    auto on_msg = (std::function<void(const std::string&)>*)closure;
    (*on_msg)(msg_str);
  }

  std::shared_ptr<opp::Subscription> Subscribe(
      const std::string& subject,
      std::function<void(const std::string&)> on_message) {
    natsSubscription* sub;
    auto status =
        natsConnection_Subscribe(&sub, nc, subject.c_str(), nullptr, nullptr);
    if (status != NATS_OK) {
      return nullptr;
    }
    auto subscription = std::make_shared<Subscription>((void*)sub);
    return subscription;
  }

  void Unsubscribe(std::shared_ptr<opp::Subscription> subscription) {
    natsSubscription* sub =
        (natsSubscription*)subscription->GetSubscriptionPtr();
    natsSubscription_Destroy(sub);
  }

 private:
  std::string host;
  int port;
  uv_loop_t* uv_loop;
  natsConnection* nc;
};

Client::Client(std::string host, int port, uv_loop_t* uv_loop)
    : impl(std::make_unique<Client::ClientImpl>(host, port, uv_loop)) {
  impl->Connect();
}

Client::~Client() {}

bool Client::Publish(const std::string& subject, const std::string&) {
  return true;
}

std::shared_ptr<opp::Subscription> Client::Subscribe(
    const std::string& subject,
    std::function<void(const std::string&)> on_message) {
  return nullptr;
}

void Client::Unsubscribe(std::shared_ptr<opp::Subscription> subscription) {}

}  // namespace messaging
}  // namespace infrastructure
}  // namespace rmsg
