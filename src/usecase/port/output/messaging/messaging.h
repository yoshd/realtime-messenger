#ifndef OUTPUT_MESSAGING_H_
#define OUTPUT_MESSAGING_H_

#include <string>

namespace rmsg {
namespace usecase {
namespace outputport {

// forward declaration
class Subscription;

class Messaging {
 public:
  virtual bool Publish(const std::string& subject,
                       const std::string& message) = 0;
  virtual std::shared_ptr<Subscription> Subscribe(
      const std::string& subject,
      std::function<void(const std::string&)> on_message) = 0;
  virtual void Unsubscribe(std::shared_ptr<Subscription> subscription) = 0;
  virtual ~Messaging() {};
};

}  // namespace outputport
}  // namespace usecase
}  // namespace rmsg

#endif
