#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

void OutputStream_destroy(UniqueObj<OutputStream>* self) {
  delete self;
}

} // extern "C"
