#include <stdbool.h>
#include <stdint.h>

typedef void *EGLStreamKHR;


// CameraDevice

extern long CameraDevice_getBasicSensorModes(const void* self, const void* sensorModes[], long maxSensorModes);
extern long CameraDevice_getAllSensorModes(const void* self, const void* sensorModes[], long maxSensorModes);


// SensorMode

extern uint32_t SensorMode_getInputBitDepth(const void* self);
extern uint32_t SensorMode_getOutputBitDepth(const void* self);


// CameraProvider

extern const void* CameraProvider_create();
extern void CameraProvider_destroy(const void* self);
//
extern void CameraProvider_reset(const void* self);
extern const char* CameraProvider_getVendor(const void* self);
extern const char* CameraProvider_getVersion(const void* self);
extern long CameraProvider_getDevices(const void* self, const void* devices[], long maxDevices);
extern const void* CameraProvider_createCaptureSession(const void* self, const void* devices[], long count);


// CaptureSession

extern void CaptureSession_destroy(const void* self);
//
extern const void* CaptureSession_createOutputStreamSettings(const void* self);
extern const void* CaptureSession_createOutputStream(const void* self, const void* outputStreamSettings);
extern const void* CaptureSession_createRequest(const void* self);
extern bool CaptureSession_repeat(const void* self, const void* captureRequest);
extern void CaptureSession_stopRepeat(const void* self);
extern void CaptureSession_waitForIdle(const void* self);


// OutputStreamSettings

extern void OutputStreamSettings_destroy(const void* self);
//
extern void OutputStreamSettings_setPixelFormat(const void* self, long pixelFormatOrdinal);
extern long OutputStreamSettings_getPixelValue(const void* self);
extern void OutputStreamSettings_setResolution(const void* self, long width, long height);
extern void OutputStreamSettings_getResolution(const void* self, long* width, long* height);
extern const void* OutputStreamSettings_getCameraDevice(const void* self);
extern void OutputStreamSettings_setCameraDevice(const void* self, const void* cameraDevice);
extern void OutputStreamSettings_setStreamMode(const void* self, long streamModeOrdinal);
extern long OutputStreamSettings_getStreamMode(const void* self);
extern void OutputStreamSettings_setFifoLength(const void* self, long fifoLength);
extern long OutputStreamSettings_getFifoLength(const void* self);


// OutputStream

extern void OutputStream_destroy(const void* self);
//
extern EGLStreamKHR OutputStream_getEGLStream(const void* self);
extern void OutputStream_reset(const void* self);
extern bool OutputStream_waitUntilConnected(const void* self, unsigned long timeout);
extern void OutputStream_disconnect(const void* self);


// Request

extern void Request_destroy(const void* self);
//
extern bool Request_enableOutputStream(const void* self, const void* outputStream);
extern const void* Request_getSourceSettings(const void* self);
extern const void* Request_getAutoControlSettings(const void* self);
extern const void* Request_getDenoiseSettings(const void* self);
extern const void* Request_getEdgeEnhanceSettings(const void* self);


// SourceSettings

extern void SourceSettings_setFrameDurationRange(const void* self, uint64_t min, uint64_t max);


//  AutoControlSettings

extern void AutoControlSettings_setMode(const void* self, long awbModeOrdinal);
extern long AutoControlSettings_getMode(const void* self);
void AutoControlSettings_setAwbLock(const void* self, bool awbLock);
bool AutoControlSettings_getAwbLock(const void* self);
void AutoControlSettings_setAeLock(const void* self, bool aeLock);
bool AutoControlSettings_getAeLock(const void* self);


// DenoiseSettings

extern void DenoiseSettings_setMode(const void* self, long denoiseModeOrdinal);
extern long DenoiseSettings_getMode(const void* self);
extern void DenoiseSettings_setStrength(const void* self, float strength);
extern float DenoiseSettings_getStrength(const void* self);


// EdgeEnhanceSettings

extern void EdgeEnhanceSettings_setMode(const void* self, long edgeEnhanceModeOrdinal);
extern long EdgeEnhanceSettings_getMode(const void* self);
extern void EdgeEnhanceSettings_setStrength(const void* self, float strength);
extern float EdgeEnhanceSettings_getStrength(const void* self);
