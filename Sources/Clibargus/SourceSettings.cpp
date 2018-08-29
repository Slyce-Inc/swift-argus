#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

void SourceSettings_setFrameDurationRange(ISourceSettings* self, uint64_t min, uint64_t max) {
  self->setFrameDurationRange(Range<uint64_t>(min, max));
}

void SourceSettings_setExposureTimeRange(ISourceSettings* self, uint64_t min, uint64_t max) {
  Range<uint64_t> range(min, max);
  self->setExposureTimeRange(range);
}

void SourceSettings_getExposureTimeRange(ISourceSettings* self, uint64_t* min, uint64_t* max) {
  Range<uint64_t> range = self->getExposureTimeRange();
  if (min) {
    *min = range.min();
  }
  if (max) {
    *max = range.max();
  }
}

} // extern "C"
