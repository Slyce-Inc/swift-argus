#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

void Request_destroy(UniqueObj<Request>* self) {
  delete self;
}

} // extern "C"
