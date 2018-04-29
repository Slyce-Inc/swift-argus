#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

void SourceSettings_setFrameDurationRange(ISourceSettings* self, uint64_t min, uint64_t max) {
  self->setFrameDurationRange(Range<uint64_t>(min, max));
}

} // extern "C"
