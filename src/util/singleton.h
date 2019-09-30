#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <utility>

namespace rmsg {
namespace util {
class SingletonFinalizer {
 public:
  typedef void (*FinalizerFunc)();

  static void AddFinalizer(FinalizerFunc func);
  static void Finalize();
};

template <typename T>
class Singleton final {
 public:
  static T* GetInstance() { return instance; }

  template <typename... Args>
  static T* Create(Args&&... args) {
    // memo:
    // std::call_onceを使いたかったが渡す関数がtemplateだと実体化できなくてだめぽい
    if (!init_flag) {
      _Create(std::forward<Args>(args)...);
      init_flag = true;
    }
    return instance;
  }

 private:
  template <typename... Args>
  static void _Create(Args&&... args) {
    instance = new T(std::forward<Args>(args)...);
    SingletonFinalizer::AddFinalizer(&Singleton<T>::Destroy);
  }

  static void Destroy() {
    delete instance;
    instance = nullptr;
  }

  static bool init_flag;
  static T* instance;
};

template <typename T>
bool Singleton<T>::init_flag = false;
template <typename T>
T* Singleton<T>::instance = nullptr;

}  // namespace util
}  // namespace rmsg

#endif  // SINGLETON_H_
