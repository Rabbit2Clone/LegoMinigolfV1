#ifndef _DISTDRIVER_C_
#define _DISTDRIVER_C_

#pragma platform(NXT)
#pragma autoStartTasks

#include "mindsensors-irdist.h"

unsigned int _Distance = 0;

task DistDeviceDriver() {
  unsigned int distance = 0;
  string type;
  wait1Msec(2000);

  while (true) {
    // Get the distance calculated based on the data from the IR Sharp module
    distance = MSDISTreadDist(MSDIST);
		nxtDisplayStringAt(62, 39, "  %02dmm  ", _Distance);
    _Distance = distance;

    wait1Msec(50);
  }
}

#endif /* _DISTDRIVER_C_ */
