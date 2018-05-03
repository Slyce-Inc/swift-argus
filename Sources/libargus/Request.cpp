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

ISourceSettings* Request_getSourceSettings(UniqueObj<Request>* self) {
  InterfaceProvider* provider = interface_cast<IRequest>(*self)->getSourceSettings();
  if (!provider) {
    return NULL;
  }
  return interface_cast<ISourceSettings>(provider);
}

IDenoiseSettings* Request_getDenoiseSettings(UniqueObj<Request>* self) {
  return interface_cast<IDenoiseSettings>(*self);
}

IEdgeEnhanceSettings* Request_getEdgeEnhanceSettings(UniqueObj<Request>* self) {
  return interface_cast<IEdgeEnhanceSettings>(*self);
}

} // extern "C"
