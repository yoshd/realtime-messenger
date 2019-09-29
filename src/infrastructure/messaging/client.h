#ifndef MESSAGING_CLIENT_H_
#define MESSAGING_CLIENT_H_

#include <string>

#include "util/singleton.h"
#include "uv.h"

#include "usecase/port/output/messaging/messaging.h"
#include "usecase/port/output/messaging/subscription.h"

namespace rmsg {
namespace infrastructure {
namespace messaging {

namespace opp = rmsg::usecase::outputport;

class Subscription final : public opp::Subscription {
 public:
  Subscription(void* sub) : sub(sub) {}
  ~Subscription() { delete sub; }

  void* GetSubscriptionPtr() override { return sub; }

 private:
  void* sub;
};

class Client final : public opp::Messaging {
 public:
  Client(std::string host, int port, uv_loop_t* uv_loop);
  ~Client() = default;

  bool Publish(const std::string& subject, const std::string&) override;
  std::shared_ptr<opp::Subscription> Subscribe(
      const std::string& subject,
      std::function<void(const std::string&)> on_message) override;
  void Unsubscribe(std::shared_ptr<opp::Subscription> subscription) override;

 private:
  // Pimpl
  class ClientImpl;
  std::unique_ptr<ClientImpl> impl;
};

static Client& CreateClient(std::string host, int port, uv_loop_t* uv_loop) {
  return util::Singleton<Client>::Create(host, port, uv_loop);
}

static Client& GetClient() { return util::Singleton<Client>::GetInstance(); }

}  // namespace messaging
}  // namespace infrastructure
}  // namespace rmsg

#endif
