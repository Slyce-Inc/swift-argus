#include <Argus/Argus.h>

using namespace Argus;

extern "C" {


static AwbMode awbModeFromOrdinal(long ordinal) {
  switch (ordinal) {
    case 1: return AWB_MODE_AUTO;
    case 2: return AWB_MODE_INCANDESCENT;
    case 3: return AWB_MODE_FLUORESCENT;
    case 4: return AWB_MODE_WARM_FLUORESCENT;
    case 5: return AWB_MODE_DAYLIGHT;
    case 6: return AWB_MODE_CLOUDY_DAYLIGHT;
    case 7: return AWB_MODE_TWILIGHT;
    case 8: return AWB_MODE_SHADE;
    case 9: return AWB_MODE_MANUAL;

    default:
      return AWB_MODE_OFF;
  }
}

static long ordinalFromAwbMode(AwbMode awbMode) {
  if (awbMode == AWB_MODE_AUTO) {
    return 1;
  } else if (awbMode == AWB_MODE_INCANDESCENT) {
    return 2;
  } else if (awbMode == AWB_MODE_FLUORESCENT) {
    return 3;
  } else if (awbMode == AWB_MODE_WARM_FLUORESCENT) {
    return 4;
  } else if (awbMode == AWB_MODE_DAYLIGHT) {
    return 5;
  } else if (awbMode == AWB_MODE_CLOUDY_DAYLIGHT) {
    return 6;
  } else if (awbMode == AWB_MODE_TWILIGHT) {
    return 7;
  } else if (awbMode == AWB_MODE_SHADE) {
    return 8;
  } else if (awbMode == AWB_MODE_MANUAL) {
    return 9;
  } else {
    return 0;
  }
}

void AutoControlSettings_setMode(IAutoControlSettings* self, long AwbModeOrdinal) {
  self->setAwbMode(awbModeFromOrdinal(AwbModeOrdinal));
}

long AutoControlSettings_getMode(IAutoControlSettings* self) {
  return ordinalFromAwbMode(self->getAwbMode());
}

void AutoControlSettings_setAwbLock(IAutoControlSettings* self, bool awbLock) {
  self->setAwbLock(awbLock);
}

bool AutoControlSettings_getAwbLock(IAutoControlSettings* self) {
  return self->getAwbLock();
}

void AutoControlSettings_setAeLock(IAutoControlSettings* self, bool aeLock) {
  self->setAeLock(aeLock);
}

bool AutoControlSettings_getAeLock(IAutoControlSettings* self) {
  return self->getAeLock();
}

} // extern "C"
