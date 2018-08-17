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

bool OutputStream_waitUntilConnected(UniqueObj<OutputStream>* self, uint64_t timeout) {
  Argus::Status status = interface_cast<IStream>(*self)->waitUntilConnected(timeout);
  return status == STATUS_OK;
}

void OutputStream_disconnect(UniqueObj<OutputStream>* self) {
  interface_cast<IStream>(*self)->disconnect();
}

} // extern "C"
