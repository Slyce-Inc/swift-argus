#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

void OutputStreamSettings_destroy(UniqueObj<OutputStreamSettings>* self) {
  delete self;
}

const void* OutputStreamSettings_getCameraDevice(UniqueObj<OutputStreamSettings>* self) {
  return interface_cast<IOutputStreamSettings>(*self)->getCameraDevice();
}

void OutputStreamSettings_setCameraDevice(UniqueObj<OutputStreamSettings>* self, CameraDevice* cameraDevice) {
  interface_cast<IOutputStreamSettings>(*self)->setCameraDevice(cameraDevice);
}

} // extern "C"
