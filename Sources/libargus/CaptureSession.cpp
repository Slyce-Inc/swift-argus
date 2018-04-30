#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

void CaptureSession_destroy(UniqueObj<CaptureSession>* self) {
  delete self;
}

UniqueObj<OutputStreamSettings>* CaptureSession_createOutputStreamSettings(UniqueObj<CaptureSession>* self) {
  return new UniqueObj<OutputStreamSettings>(interface_cast<ICaptureSession>(*self)->createOutputStreamSettings());
}

UniqueObj<OutputStream>* CaptureSession_createOutputStream(UniqueObj<CaptureSession>* self, UniqueObj<OutputStreamSettings>*  outputStreamSettings) {
  return new UniqueObj<OutputStream>(interface_cast<ICaptureSession>(*self)->createOutputStream(outputStreamSettings->get()));
}

UniqueObj<Request>* CaptureSession_createRequest(UniqueObj<CaptureSession>* self) {
  return new UniqueObj<Request>(interface_cast<ICaptureSession>(*self)->createRequest());
}

bool CaptureSession_repeat(UniqueObj<CaptureSession>* self, UniqueObj<Request>* captureRequest) {
  int status = interface_cast<ICaptureSession>(*self)->repeat(captureRequest->get());
  return status == STATUS_OK;
}

void CaptureSession_stopRepeat(UniqueObj<CaptureSession>* self) {
  interface_cast<ICaptureSession>(*self)->stopRepeat();
}

void CaptureSession_waitForIdle(UniqueObj<CaptureSession>* self) {
  interface_cast<ICaptureSession>(*self)->waitForIdle();
}

} // extern "C"
