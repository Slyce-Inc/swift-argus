#include <Argus/Argus.h>

using namespace Argus;

extern "C" {

long CameraDevice_getBasicSensorModes(CameraDevice* self, const void* sensorModes[], long maxSensorModes) {
  std::vector<SensorMode*> sm;
  if (interface_cast<ICameraProperties>(self)->getBasicSensorModes(&sm) != STATUS_OK) {
    return 0;
  }
  int numberToReturn = std::min(maxSensorModes, long(sm.size()));
  for (int i = 0; i < numberToReturn; i++) {
    sensorModes[i] = sm[i];
  }
  return numberToReturn;
}

long CameraDevice_getAllSensorModes(CameraDevice* self, const void* sensorModes[], long maxSensorModes) {
  std::vector<SensorMode*> sm;
  if (interface_cast<ICameraProperties>(self)->getAllSensorModes(&sm) != STATUS_OK) {
    return 0;
  }
  int numberToReturn = std::min(maxSensorModes, long(sm.size()));
  for (int i = 0; i < numberToReturn; i++) {
    sensorModes[i] = sm[i];
  }
  return numberToReturn;
}

}
