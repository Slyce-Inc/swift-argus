#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

void Request_destroy(UniqueObj<Request>* self) {
  delete self;
}

bool Request_enableOutputStream(UniqueObj<Request>* self, UniqueObj<OutputStream>* outputStream) {
  Argus::Status status = interface_cast<IRequest>(*self)->enableOutputStream(outputStream->get());
  return status == STATUS_OK;
}

} // extern "C"
