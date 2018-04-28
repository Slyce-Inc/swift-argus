#include <stdbool.h>

// CameraProvider

extern const void* CameraProvider_create();
extern void CameraProvider_destroy(const void* self);

extern void CameraProvider_reset(const void* self);
extern const char* CameraProvider_getVendor(const void* self);
extern const char* CameraProvider_getVersion(const void* self);
extern long CameraProvider_getDevices(const void* self, const void* devices[], long maxDevices);
extern const void* CameraProvider_createCaptureSession(const void* self, const void* devices[], long count);


// CaptureSession

extern void CaptureSession_destroy(const void* self);

extern const void* CaptureSession_createOutputStreamSettings(const void* self);
extern const void* CaptureSession_createOutputStream(const void* self, const void* outputStreamSettings);
extern const void* CaptureSession_createRequest(const void* self);


// OutputStreamSettings

extern void OutputStreamSettings_destroy(const void* self);

extern void OutputStreamSettings_setPixelFormat(const void* self, long pixelFormatOrdinal);
extern long OutputStreamSettings_getPixelValue(const void* self);
extern void OutputStreamSettings_setResolution(const void* self, long width, long height);
extern void OutputStreamSettings_getResolution(const void* self, long* width, long* height);
extern const void* OutputStreamSettings_getCameraDevice(const void* self);
extern void OutputStreamSettings_setCameraDevice(const void* self, const void* cameraDevice);


// OutputStream

extern void OutputStream_destroy(const void* self);


// Request

extern void Request_destroy(const void* self);
extern bool Request_enableOutputStream(const void* self, const void* outputStream);
