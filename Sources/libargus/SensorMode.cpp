#include <Argus/Argus.h>
#include <stdio.h>

using namespace Argus;

extern "C" {

uint32_t SensorMode_getInputBitDepth(SensorMode* self) {
  return interface_cast<ISensorMode>(self)->getInputBitDepth();
}

uint32_t SensorMode_getOutputBitDepth(SensorMode* self) {
  return interface_cast<ISensorMode>(self)->getOutputBitDepth();
}

}
