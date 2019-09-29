#ifndef OUTPUT_MSTORE_H_
#define OUTPUT_MSTORE_H_

#include <string>

namespace rmsg {
namespace usecase {
namespace outputport {

class MemoryStore {
 public:
  struct Result {
    bool ok;
    std::string value;
  };

  virtual void GetValue(
      const std::string& key,
      std::function<void(const std::shared_ptr<Result>)> on_get_value) = 0;

  virtual void SetValue(
      const std::string& key, const std::string& value,
      std::function<void(const std::shared_ptr<Result>)> on_set_value) = 0;

  virtual void DeleteValue(
      const std::string& key,
      std::function<void(const std::shared_ptr<Result>)> on_delete_value) = 0;

  virtual ~MemoryStore() {}
};

}  // namespace outputport
}  // namespace usecase
}  // namespace rmsg

#endif
