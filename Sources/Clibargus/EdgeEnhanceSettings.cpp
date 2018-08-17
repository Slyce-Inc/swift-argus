#include <Argus/Argus.h>

using namespace Argus;

extern "C" {


static EdgeEnhanceMode EdgeEnhanceModeFromOrdinal(long ordinal) {
  switch (ordinal) {
    case 1: return EDGE_ENHANCE_MODE_FAST;
    case 2: return EDGE_ENHANCE_MODE_HIGH_QUALITY;

    default:
      return EDGE_ENHANCE_MODE_OFF;
  }
}

static long ordinalFromEdgeEnhanceMode(EdgeEnhanceMode edgeEnhanceMode) {
  if (edgeEnhanceMode == EDGE_ENHANCE_MODE_FAST) {
    return 1;
  } else if (edgeEnhanceMode == EDGE_ENHANCE_MODE_HIGH_QUALITY) {
    return 2;
  } else {
    return 0;
  }
}

void EdgeEnhanceSettings_setMode(IEdgeEnhanceSettings* self, long edgeEnhanceModeOrdinal) {
  self->setEdgeEnhanceMode(EdgeEnhanceModeFromOrdinal(edgeEnhanceModeOrdinal));
}

long EdgeEnhanceSettings_getMode(IEdgeEnhanceSettings* self) {
  return ordinalFromEdgeEnhanceMode(self->getEdgeEnhanceMode());
}

void EdgeEnhanceSettings_setStrength(IEdgeEnhanceSettings* self, float strength) {
  self->setEdgeEnhanceStrength(strength);
}

float EdgeEnhanceSettings_getStrength(IEdgeEnhanceSettings* self) {
  return self->getEdgeEnhanceStrength();
}

} // extern "C"
