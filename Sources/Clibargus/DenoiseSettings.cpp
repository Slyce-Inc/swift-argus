#include <Argus/Argus.h>

using namespace Argus;

extern "C" {


static DenoiseMode denoiseModeFromOrdinal(long ordinal) {
  switch (ordinal) {
    case 1: return DENOISE_MODE_FAST;
    case 2: return DENOISE_MODE_HIGH_QUALITY;

    default:
      return DENOISE_MODE_OFF;
  }
}

static long ordinalFromDenoiseMode(DenoiseMode denoiseMode) {
  if (denoiseMode == DENOISE_MODE_FAST) {
    return 1;
  } else if (denoiseMode == DENOISE_MODE_HIGH_QUALITY) {
    return 2;
  } else {
    return 0;
  }
}

void DenoiseSettings_setMode(IDenoiseSettings* self, long denoiseModeOrdinal) {
  self->setDenoiseMode(denoiseModeFromOrdinal(denoiseModeOrdinal));
}

long DenoiseSettings_getMode(IDenoiseSettings* self) {
  return ordinalFromDenoiseMode(self->getDenoiseMode());
}

void DenoiseSettings_setStrength(IDenoiseSettings* self, float strength) {
  self->setDenoiseStrength(strength);
}

float DenoiseSettings_getStrength(IDenoiseSettings* self) {
  return self->getDenoiseStrength();
}

} // extern "C"
