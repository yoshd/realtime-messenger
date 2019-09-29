#ifndef OUTPUT_SUBSCRIPTION_H_
#define OUTPUT_SUBSCRIPTION_H_

#include <string>

namespace rmsg {
namespace usecase {
namespace outputport {

class Subscription {
 public:
  virtual void* GetSubscriptionPtr() = 0;
  virtual ~Subscription() {};
};

}  // namespace outputport
}  // namespace usecase
}  // namespace rmsg

#endif
