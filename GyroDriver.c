///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	GryroDriver NEW 2013_06_18
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GYRODRIVER_C_
#define _GYRODRIVER_C_

float _fGyroAngle      = 0.0;              // The absolute angle calculated by the device driver
bool _GyrodriverInitFinish = false;


#include "hitechnic-gyro.h"

task GyroDeviceDriver()
{
	float rotSpeed = 0;
  float heading = 0;

  nSchedulePriority = kHighPriority - 8;
  wait1Msec(2000);
  HTGYROstartCal(HTGYRO);
  //PlaySound(soundBeepBeep);
  wait1Msec(2000);
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
    //wait1Msec(5);

    // Reset the timer
    time1[T1]=0;

    // Read the current rotation speed
    rotSpeed = HTGYROreadRot(HTGYRO);

    heading  += rotSpeed * 0.02;
    _fGyroAngle = heading;
    nxtDisplayStringAt(62, 48, "  %03d   ", (int)_fGyroAngle);

  }
}

task getHeading ()
{
	float delTime = 0;
	float prevHeading = 0;
	float curRate = 0;
	nSchedulePriority = kHighPriority - 8;
	wait1Msec(2000);
  HTGYROstartCal(HTGYRO);
  wait1Msec(2000);
  _GyrodriverInitFinish = true;
  while (true) {
    time1[T1] = 0;
    curRate = HTGYROreadRot(HTGYRO);
    if (abs(curRate) > 1) {
      prevHeading = _fGyroAngle;
      _fGyroAngle = prevHeading + curRate * delTime;
      //if (currHeading > 360) currHeading -= 360;
      //else if (currHeading < 0) currHeading += 360;
    }
    wait1Msec(5);
    delTime = ((float)time1[T1]) / 1000;
    nxtDisplayStringAt(62, 48, "  %03d   ", (int)_fGyroAngle);
    //delTime /= 1000;
  }
}

#endif
