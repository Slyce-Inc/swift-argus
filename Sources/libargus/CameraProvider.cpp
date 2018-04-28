#include <Argus/Argus.h>
#include <algorithm>

using namespace Argus;

extern "C" {

UniqueObj<CameraProvider>* CameraProvider_create() {
  return new UniqueObj<CameraProvider>(CameraProvider::create());
}

void CameraProvider_destroy(UniqueObj<CameraProvider>* self) {
  delete self;
}

void CameraProvider_reset(UniqueObj<CameraProvider>* self) {
  self->reset();
}

const char* CameraProvider_getVendor(UniqueObj<CameraProvider>* self) {
  return interface_cast<ICameraProvider>(*self)->getVendor().c_str();
}

const char* CameraProvider_getVersion(UniqueObj<CameraProvider>* self) {
  return interface_cast<ICameraProvider>(*self)->getVersion().c_str();
}

long CameraProvider_getDevices(UniqueObj<CameraProvider>* self, CameraDevice** devices, long maxDevices) {
  std::vector<CameraDevice*> cd;
  if (interface_cast<ICameraProvider>(*self)->getCameraDevices(&cd) != STATUS_OK) {
    return 0;
  }
  int numberToReturn = std::min(maxDevices, long(cd.size()));
  for (int i = 0; i < numberToReturn; i++) {
    devices[i] = cd[i];
  }
  return numberToReturn;
}

void* CameraProvider_createCaptureSession(UniqueObj<CameraProvider>* self, CameraDevice** devices, long count) {
  std::vector<CameraDevice*> cd;
  for (int i = 0; i < count; i++) {
    cd.push_back(devices[i]);
  }
  return interface_cast<ICameraProvider>(*self)->createCaptureSession(cd);
}

} // extern "C"
