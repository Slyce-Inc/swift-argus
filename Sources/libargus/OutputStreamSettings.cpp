#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

void OutputStreamSettings_destroy(UniqueObj<OutputStreamSettings>* self) {
  delete self;
}

} // extern "C"
