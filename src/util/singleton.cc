#include "./singleton.h"

namespace rmsg {
namespace util {
const int MaxFinalizerSize = 256;
static int NumFinalizerSize = 0;

static SingletonFinalizer::FinalizerFunc Finalizers[MaxFinalizerSize];

void SingletonFinalizer::AddFinalizer(SingletonFinalizer::FinalizerFunc func) {
  Finalizers[NumFinalizerSize] = func;
  ++NumFinalizerSize;
}

void SingletonFinalizer::Finalize() {
  for (int i = NumFinalizerSize - 1; i >= 0; --i) {
    (*Finalizers[i])();
  }
}

}  // namespace util
}  // namespace rmsg