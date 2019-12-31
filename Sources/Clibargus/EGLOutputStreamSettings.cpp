#include <Argus/Argus.h>

using namespace Argus;

extern "C" {


static PixelFormat pixelFormatFromOrdinal(long ordinal) {
  switch (ordinal) {
    case 1: return PIXEL_FMT_Y8;
    case 2: return PIXEL_FMT_Y16;
    case 3: return PIXEL_FMT_YCbCr_420_888;
    case 4: return PIXEL_FMT_YCbCr_422_888;
    case 5: return PIXEL_FMT_YCbCr_444_888;
    case 6: return PIXEL_FMT_JPEG_BLOB;
    case 7: return PIXEL_FMT_RAW16;

    default:
      return PIXEL_FMT_UNKNOWN;
  }
}

static long ordinalFromPixelFormat(PixelFormat pixelFormat) {
  if (pixelFormat == PIXEL_FMT_Y8) {
    return 1;
  } else if (pixelFormat == PIXEL_FMT_Y16) {
    return 2;
  } else if (pixelFormat == PIXEL_FMT_YCbCr_420_888) {
    return 3;
  } else if (pixelFormat == PIXEL_FMT_YCbCr_422_888) {
    return 4;
  } else if (pixelFormat == PIXEL_FMT_YCbCr_444_888) {
    return 5;
  } else if (pixelFormat == PIXEL_FMT_JPEG_BLOB) {
    return 6;
  } else if (pixelFormat == PIXEL_FMT_RAW16) {
    return 7;
  } else {
    return 0;
  }
}

static EGLStreamMode eglStreamModeFromOrdinal(long ordinal) {
  switch (ordinal) {
    case 1: return EGL_STREAM_MODE_MAILBOX;
    case 2: return EGL_STREAM_MODE_FIFO;
  }
  assert(false);
}

static long ordinalFromEGLStreamMode(EGLStreamMode streamMode) {
  if (streamMode == EGL_STREAM_MODE_MAILBOX) {
    return 1;
  } else if (streamMode == EGL_STREAM_MODE_FIFO) {
    return 2;
  }
  assert(false);
}

void EGLOutputStreamSettings_setPixelFormat(UniqueObj<OutputStreamSettings>* self, long pixelFormatOrdinal) {
  interface_cast<IEGLOutputStreamSettings>(*self)->setPixelFormat(pixelFormatFromOrdinal(pixelFormatOrdinal));
}

long EGLOutputStreamSettings_getPixelValue(UniqueObj<OutputStreamSettings>* self) {
  return ordinalFromPixelFormat(interface_cast<IEGLOutputStreamSettings>(*self)->getPixelFormat());
}

void EGLOutputStreamSettings_setResolution(UniqueObj<OutputStreamSettings>* self, long width, long height) {
  Argus::Size2D<uint32_t> resolution((uint32_t)width, (uint32_t)height);
  interface_cast<IEGLOutputStreamSettings>(*self)->setResolution(resolution);
}

void EGLOutputStreamSettings_getResolution(UniqueObj<OutputStreamSettings>* self, long* width, long* height) {
  Size2D<uint32_t> resolution = interface_cast<IEGLOutputStreamSettings>(*self)->getResolution();
  *width = resolution.width();
  *height = resolution.height();
}

void EGLOutputStreamSettings_setEGLStreamMode(UniqueObj<OutputStreamSettings>* self, long eglStreamModeOrdinal) {
  interface_cast<IEGLOutputStreamSettings>(*self)->setMode(eglStreamModeFromOrdinal(eglStreamModeOrdinal));
}

long EGLOutputStreamSettings_getEGLStreamMode(UniqueObj<OutputStreamSettings>* self) {
  return ordinalFromEGLStreamMode(interface_cast<IEGLOutputStreamSettings>(*self)->getMode());
}

void EGLOutputStreamSettings_setFifoLength(UniqueObj<OutputStreamSettings>* self, long fifoLength) {
  interface_cast<IEGLOutputStreamSettings>(*self)->setFifoLength(fifoLength);
}

long EGLOutputStreamSettings_getFifoLength(UniqueObj<OutputStreamSettings>* self) {
  return interface_cast<IEGLOutputStreamSettings>(*self)->getFifoLength();
}

} // extern "C"
