#include "./realtime_messenger_service.h"

#include "domain/entity/room.h"
#include "infrastructure/mstore/mstore_client.h"
#include "usecase/port/output/streaming/streaming.h"

namespace rmsg {
namespace service {

grpc::Status RealtimeMessengerService::Login(grpc::ServerContext *context,
                                             const rmsg::LoginReq *request,
                                             rmsg::LoginRes *response) {
  auto ok = interactor->Login(request->user_id());
  if (ok) {
    return grpc::Status::OK;
  }
  return grpc::Status::CANCELLED;
}

grpc::Status RealtimeMessengerService::Logout(grpc::ServerContext *context,
                                              const rmsg::LogoutReq *request,
                                              rmsg::LogoutRes *response) {
  auto ok = interactor->Logout(request->user_id());
  if (ok) {
    return grpc::Status::OK;
  }
  return grpc::Status::CANCELLED;
}

grpc::Status RealtimeMessengerService::CreateRoom(
    grpc::ServerContext *context, const rmsg::CreateRoomReq *request,
    rmsg::CreateRoomRes *response) {
  auto room = std::make_shared<domain::entity::Room>(
      request->room_id(), static_cast<int>(request->max_capacity()));
  auto ok = interactor->CreateRoom(room);
  if (ok) {
    return grpc::Status::OK;
  }
  return grpc::Status::CANCELLED;
}

grpc::Status RealtimeMessengerService::JoinRoom(
    grpc::ServerContext *context, const rmsg::JoinRoomReq *request,
    rmsg::JoinRoomRes *response) {
  auto ok = interactor->JoinRoom(request->room_id(), request->user_id());
  if (ok) {
    return grpc::Status::OK;
  }
  return grpc::Status::CANCELLED;
}

grpc::Status RealtimeMessengerService::LeaveRoom(
    grpc::ServerContext *context, const rmsg::LeaveRoomReq *request,
    rmsg::LeaveRoomRes *response) {
  auto ok = interactor->LeaveRoom(request->user_id());
  if (ok) {
    return grpc::Status::OK;
  }
  return grpc::Status::CANCELLED;
}

grpc::Status RealtimeMessengerService::StartMessageStream(
    grpc::ServerContext *context,
    grpc::ServerReaderWriter<rmsg::Message, rmsg::Message> *stream) {
  auto _stream = std::make_shared<usecase::outputport::Stream<
      grpc::ServerReaderWriter<rmsg::Message, rmsg::Message>, rmsg::Message,
      grpc::WriteOptions>>(stream);

  std::multimap<grpc::string_ref, grpc::string_ref> metadata =
      context->client_metadata();
  auto user_id = metadata.find("user_id")->second;
  auto user_id_str = std::string(user_id.data(), user_id.size());
  auto user =
      std::make_shared<domain::entity::User<usecase::outputport::Subscription>>(
          user_id_str);
  interactor->StartMessageStream<
      grpc::ServerReaderWriter<rmsg::Message, rmsg::Message>, rmsg::Message,
      grpc::WriteOptions>(user, _stream);

  return grpc::Status::OK;
}

}  // namespace service
}  // namespace rmsg
