#ifndef INTERACTOR_H_
#define INTERACTOR_H_

#include <string>

#include "domain/entity/room.h"
#include "domain/entity/user.h"
#include "usecase/port/output/messaging/messaging.h"
#include "usecase/port/output/messaging/subscription.h"
#include "usecase/port/output/mstore/mstore.h"
#include "usecase/port/output/streaming/streaming.h"

namespace rmsg {
namespace usecase {
namespace interactor {

using namespace rmsg::domain;

class RealtimeMessengerInteractor {
 public:
  RealtimeMessengerInteractor(std::shared_ptr<outputport::MemoryStore> mstore,
                              std::shared_ptr<outputport::Messaging> messaging)
      : mstore(mstore), messaging(messaging){};

  bool Login(const std::string& user_id) {
    // Todo: async api, value, error handling
    mstore->GetValue(
        // 雑
        user_id, [&](std::shared_ptr<outputport::MemoryStore::Result> result) {
          if (result->value.empty()) {
            mstore->SetValue(user_id, "logged_in", nullptr);
          }
        });
    return true;
  };

  bool Logout(const std::string& user_id) {
    // Todo: async api
    mstore->GetValue(
        // 雑
        user_id, [&](std::shared_ptr<outputport::MemoryStore::Result> result) {
          if (result->ok && !result->value.empty()) {
            mstore->DeleteValue(user_id, nullptr);
          }
        });
    return true;
  }

  bool CreateRoom(std::shared_ptr<entity::Room> room) {
    // Todo: async api
    mstore->GetValue(
        // 雑
        room->GetRoomId(),
        [&](std::shared_ptr<outputport::MemoryStore::Result> result) {
          if (result->value.empty()) {
            mstore->SetValue(room->GetRoomId(),
                             std::to_string(room->GetCapacity()), nullptr);
          }
        });
    return true;
  }

  bool JoinRoom(const std::string& room_id, const std::string& user_id) {
    // Todo: async api
    mstore->GetValue(
        // 雑
        room_id, [&](std::shared_ptr<outputport::MemoryStore::Result> result) {
          if (result->ok && !result->value.empty()) {
            mstore->SetValue(user_id, room_id, nullptr);
          }
        });
    return true;
  }

  bool LeaveRoom(const std::string& user_id) {
    // Todo: async api
    mstore->GetValue(
        // 雑
        user_id, [&](std::shared_ptr<outputport::MemoryStore::Result> result) {
          if (result->ok && !result->value.empty()) {
            mstore->SetValue(user_id, "", nullptr);
          }
        });
  }

  template <typename ReaderWriter, typename Message, typename WriteOptions>
  void StartMessageStream(
      std::shared_ptr<entity::User<outputport::Subscription>> user,
      std::shared_ptr<outputport::Stream<ReaderWriter, Message>> stream) {
    // Todo: async api
    mstore->GetValue(
        // 雑
        user->GetId(), [&](std::shared_ptr<outputport::MemoryStore::Result> result) {
          if (result->ok && !result->value.empty()) {
            auto sub = messaging->Subscribe(user->GetId(),
                                            [&](const std::string& message) {
                                              Message msg;
                                              WriteOptions opts;
                                              msg.set_msg(message);
                                              stream->Write<WriteOptions>(msg, opts);
                                            });
            user->SetSubscription(sub);

            Message msg;
            while (stream->Read(&msg)) {
              messaging->Publish(msg.user_id(), msg.msg());
            }
          }
        });
  }

 private:
  std::shared_ptr<outputport::MemoryStore> mstore;
  std::shared_ptr<outputport::Messaging> messaging;
};

}  // namespace interactor
}  // namespace usecase
}  // namespace rmsg

#endif  // INTERACTOR_H_
