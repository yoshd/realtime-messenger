#ifndef MSTORE_CLIENT_H_
#define MSTORE_CLIENT_H_

#include <string>

#include "uv.h"

#include "usecase/port/output/mstore/mstore.h"
#include "util/singleton.h"

namespace rmsg {
namespace mstore {

namespace opp = rmsg::usecase::outputport;
using Result = opp::MemoryStore::Result;

class Client final : public opp::MemoryStore {
 public:
  Client(std::string host, int port, uv_loop_t* uv_loop);

  // pimplのため自動生成されるデストラクタのインライン展開ができないので
  ~Client();

  void GetValue(
      const std::string& key,
      std::function<void(const std::shared_ptr<Result>)> on_get_value) override;

  void SetValue(
      const std::string& key, const std::string& value,
      std::function<void(const std::shared_ptr<Result>)> on_set_value) override;

  void DeleteValue(const std::string& key,
                   std::function<void(const std::shared_ptr<Result>)>
                       on_delete_value) override;

 private:
  // Pimpl
  class ClientImpl;
  std::unique_ptr<ClientImpl> impl;
};

static Client* CreateClient(std::string host, int port, uv_loop_t* uv_loop) {
  return util::Singleton<Client>::Create(host, port, uv_loop);
}

static Client* GetClient() { return util::Singleton<Client>::GetInstance(); }

}  // namespace mstore
}  // namespace rmsg

#endif  // MSTORE_CLIENT_H_
