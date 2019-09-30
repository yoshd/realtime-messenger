#ifndef REALTIME_MESSENGER_SERVER_H_
#define REALTIME_MESSENGER_SERVER_H_

#include <grpc++/grpc++.h>

#include "gen/protobuf/realtime_messenger.grpc.pb.h"
#include "gen/protobuf/realtime_messenger.pb.h"
#include "usecase/interactor/interactor.h"
#include "usecase/port/output/messaging/messaging.h"
#include "usecase/port/output/mstore/mstore.h"

namespace rmsg {
namespace service {
class RealtimeMessengerService final : public rmsg::RealtimeMessenger::Service {
 public:
  RealtimeMessengerService(
      std::shared_ptr<usecase::interactor::RealtimeMessengerInteractor>
          interactor)
      : interactor(interactor) {}

  grpc::Status Login(grpc::ServerContext *context,
                     const rmsg::LoginReq *request,
                     rmsg::LoginRes *response) override;

  grpc::Status Logout(grpc::ServerContext *context,
                      const rmsg::LogoutReq *request,
                      rmsg::LogoutRes *response) override;

  grpc::Status CreateRoom(grpc::ServerContext *context,
                          const rmsg::CreateRoomReq *request,
                          rmsg::CreateRoomRes *response) override;

  grpc::Status JoinRoom(grpc::ServerContext *context,
                        const rmsg::JoinRoomReq *request,
                        rmsg::JoinRoomRes *response) override;

  grpc::Status LeaveRoom(grpc::ServerContext *context,
                         const rmsg::LeaveRoomReq *request,
                         rmsg::LeaveRoomRes *response) override;

  grpc::Status StartMessageStream(
      grpc::ServerContext *context,
      grpc::ServerReaderWriter<rmsg::Message, rmsg::Message> *stream) override;

  ~RealtimeMessengerService(){};

 private:
  std::shared_ptr<usecase::interactor::RealtimeMessengerInteractor> interactor;
};

}  // namespace service
}  // namespace rmsg

#endif  // REALTIME_MESSENGER_SERVER_H_
