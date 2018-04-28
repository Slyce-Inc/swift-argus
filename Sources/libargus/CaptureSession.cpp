#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

void CaptureSession_destroy(UniqueObj<CaptureSession>* self) {
  delete self;
}

UniqueObj<OutputStreamSettings>* CaptureSession_createOutputStreamSettings(UniqueObj<CaptureSession>* self) {
  return new UniqueObj<OutputStreamSettings>(interface_cast<ICaptureSession>(*self)->createOutputStreamSettings());
}

} // extern "C"
