#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

void OutputStream_destroy(UniqueObj<OutputStream>* self) {
  delete self;
}

EGLStreamKHR OutputStream_getEGLStream(UniqueObj<OutputStream>* self) {
  return interface_cast<IStream>(*self)->getEGLStream();
}

void OutputStream_reset(UniqueObj<OutputStream>* self) {
  self->reset();
}

} // extern "C"
