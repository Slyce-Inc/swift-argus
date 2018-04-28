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


void OutputStreamSettings_destroy(UniqueObj<OutputStreamSettings>* self) {
  delete self;
}

void OutputStreamSettings_setPixelFormat(UniqueObj<OutputStreamSettings>* self, long pixelFormatOrdinal) {
  interface_cast<IOutputStreamSettings>(*self)->setPixelFormat(pixelFormatFromOrdinal(pixelFormatOrdinal));
}

long OutputStreamSettings_getPixelValue(UniqueObj<OutputStreamSettings>* self) {
  return ordinalFromPixelFormat(interface_cast<IOutputStreamSettings>(*self)->getPixelFormat());
}

void OutputStreamSettings_setResolution(UniqueObj<OutputStreamSettings>* self, long width, long height) {
  Argus::Size2D<uint32_t> resolution((uint32_t)width, (uint32_t)height);
  interface_cast<IOutputStreamSettings>(*self)->setResolution(resolution);
}

void OutputStreamSettings_getResolution(UniqueObj<OutputStreamSettings>* self, long* width, long* height) {
  Size2D<uint32_t> resolution = interface_cast<IOutputStreamSettings>(*self)->getResolution();
  *width = resolution.width();
  *height = resolution.height();
}

} // extern "C"
