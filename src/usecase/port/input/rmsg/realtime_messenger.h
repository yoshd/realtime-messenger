#ifndef INPUT_RMSG_H_
#define INPUT_RMSG_H_

#include <string>

#include "domain/entity/room.h"
#include "domain/entity/user.h"
#include "usecase/port/output/messaging/subscription.h"
#include "usecase/port/output/streaming/streaming.h"

namespace rmsg {
namespace usecase {
namespace inputport {

class RealtimeMessenger {
 public:
  virtual bool Login(const std::string& user_id) = 0;
  virtual bool Logout(const std::string& user_id) = 0;
  virtual bool CreateRoom(std::shared_ptr<entity::Room> room) = 0;
  virtual bool JoinRoom(const std::string& room_id, const std::string& user_id) = 0;
  virtual bool LeaveRoom(const std::string& user_id) = 0;
  template <typename ReaderWriter, typename Message, typename WriteOptions>
  virtual void StartMessageStream(
      std::shared_ptr<entity::User<outputport::Subscription>> user,
      std::shared_ptr<outputport::Stream<ReaderWriter, Message>> stream) = 0;
  virtual ~RealtimeMessenger() {}
};

}  // namespace inputport
}  // namespace usecase
}  // namespace rmsg

#endif
