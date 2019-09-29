#include "./realtime_messenger_service.h"

#include <iostream>

#include "infrastructure/mstore/mstore_client.h"

namespace rmsg {
namespace service {

void f(const std::shared_ptr<rmsg::mstore::Client::Result> r) {
  std::cout << "result_value:" << r->value << std::endl;
  std::cout << "result_status" << r->ok << std::endl;
}

grpc::Status RealtimeMessengerService::Login(grpc::ServerContext *context,
                                             const rmsg::LoginReq *request,
                                             rmsg::LoginRes *response) {
  std::cout << "Login呼ばれた" << std::endl;
  std::cout << "Redisにkey登録する感じの実装する(distributed lock)"
            << std::endl;

  auto &mstore_client = rmsg::mstore::GetClient();

  mstore_client.SetValue(request->user_id(), "loggedin", f);

  return grpc::Status::OK;
}

grpc::Status RealtimeMessengerService::Logout(grpc::ServerContext *context,
                                              const rmsg::LogoutReq *request,
                                              rmsg::LogoutRes *response) {
  return grpc::Status::OK;
}

grpc::Status RealtimeMessengerService::CreateRoom(
    grpc::ServerContext *context, const rmsg::CreateRoomReq *request,
    rmsg::CreateRoomRes *response) {
  return grpc::Status::OK;
}

grpc::Status RealtimeMessengerService::JoinRoom(
    grpc::ServerContext *context, const rmsg::JoinRoomReq *request,
    rmsg::JoinRoomRes *response) {
  return grpc::Status::OK;
}

grpc::Status RealtimeMessengerService::LeaveRoom(
    grpc::ServerContext *context, const rmsg::LeaveRoomReq *request,
    rmsg::LeaveRoomRes *response) {
  return grpc::Status::OK;
}

grpc::Status RealtimeMessengerService::StartMessageStream(
    grpc::ServerContext *context,
    grpc::ServerReaderWriter<rmsg::Message, rmsg::Message> *stream) {
  return grpc::Status::OK;
}

}  // namespace service
}  // namespace rmsg
