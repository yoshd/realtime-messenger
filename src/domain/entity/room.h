#ifndef ENTITY_ROOM_H_
#define ENTITY_ROOM_H_

#include <string>

namespace rmsg {
namespace domain {
namespace entity {

class Room {
 public:
  Room(const std::string& room_id, int capacity)
      : room_id(room_id), capacity(capacity) {}

  const std::string& GetRoomId() { return room_id; }
  int GetCapacity() { return capacity; }

 private:
  std::string room_id;
  int capacity;
};

}  // namespace entity
}  // namespace domain
}  // namespace rmsg

#endif
