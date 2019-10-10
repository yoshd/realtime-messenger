#ifndef ENTITY_USER_H_
#define ENTITY_USER_H_

#include <string>

namespace rmsg {
namespace domain {
namespace entity {

template <class Subscription>
class User {
 public:
  User(const std::string& id) : id(id), sub(nullptr) {}

  const std::string& GetId() { return id; }

  std::shared_ptr<Subscription> GetSubscription() { return sub; }
  void SetSubscription(std::shared_ptr<Subscription> sub) { sub = sub; }

 private:
  std::string id;
  std::shared_ptr<Subscription> sub;
};

}  // namespace entity
}  // namespace domain
}  // namespace rmsg

#endif
