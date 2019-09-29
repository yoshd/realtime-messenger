#ifndef OUTPUT_STREAMING_H_
#define OUTPUT_STREAMING_H_

namespace rmsg {
namespace usecase {
namespace outputport {

template <typename ReaderWriter, typename Message>
class Stream {
 public:
  Stream(ReaderWriter* rw) : rw(rw) {}
  bool Read(Message* m) { return rw->Read(m); }
  template <typename WriteOptions>
  bool Write(Message m, WriteOptions opts) {
    return rw->Write(m, opts);
  }

 private:
  ReaderWriter* rw;
};

}  // namespace outputport
}  // namespace usecase
}  // namespace rmsg

#endif
