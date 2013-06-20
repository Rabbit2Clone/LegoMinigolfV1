///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	GryroDriver NEW 2013_06_18
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GYRODRIVER_C_
#define _GYRODRIVER_C_

#pragma platform(NXT)
#pragma autoStartTasks


float _fGyroAngle      = 0.0;              // The absolute angle calculated by the device driver
bool _GyrodriverInitFinish = false;


#include "hitechnic-gyro.h"

task GyroDeviceDriver()
{
	float rotSpeed = 0;
  float heading = 0;

  nSchedulePriority = kHighPriority - 8;
  wait1Msec(1000);
  HTGYROstartCal(HTGYRO);
  wait1Msec(3000);
  _GyrodriverInitFinish = true;


  // Reset the timer.
  time1[T1] = 0;

  while (true)
  {
    // Wait until 20ms has passed
    while (time1[T1] < 20)
    {
      wait1Msec(1);
    }

    // Reset the timer
    time1[T1]=0;

    // Read the current rotation speed
    rotSpeed = HTGYROreadRot(HTGYRO);

    heading  += rotSpeed * 0.02;
    _fGyroAngle = heading;
    nxtDisplayStringAt(62, 48, "  %03d   ", (int)_fGyroAngle);

  }
}

#endif
