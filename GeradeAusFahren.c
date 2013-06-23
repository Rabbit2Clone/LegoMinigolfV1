#ifndef _GERADEAUSFAHREN_C_
#define _GERADEAUSFAHREN_C_

//#include "GyroDriver.c"

void driveDistance(unsigned int distance)
{
	int fAngleDrive = (int)_fGyroAngle;
	nSyncedMotors = synchBC;
	nSyncedTurnRatio = 100;

	distance = (unsigned int)((float)distance *2.010378);
	// Durchmesser Rad = 57mm -> u = 179.07078mm ; Encoder lst auf 360Grad auf => 1mm= 2.010378 Grad

	while(distance)
	{
		nMotorEncoder[motorB] = 0;                // reset the Motor Encoder of Motor B
		nSyncedMotors = synchBC;
		nSyncedTurnRatio = 100;
		if(distance/100)
		{
			nMotorEncoderTarget[motorB] = 100;        //
			//nMotorEncoderTarget[motorC] = 100;

			distance -= 100;
		}
		else
		{
			nMotorEncoderTarget[motorB] = distance;        //
			//nMotorEncoderTarget[motorC] = distance;        //
			distance = 0;
		}
		motor[motorB] = 7;                       // motor C is run at a power level of 8
		//motor[motorC] = 15;

		while(nMotorRunState[motorB] != runStateIdle)
		{
			EndTimeSlice();
		}
		motor[motorB] = 0;
		if(((int)_fGyroAngle- fAngleDrive) >= 1) // Fahrkorrektur
		{
			turn_left(10);
		}
		else if(((int)_fGyroAngle- fAngleDrive) <= -1)
		{
			turn_right(10);
		}
		motor[motorB] = 0;                       // motor C is stopped at a power level of 0
	}
	nSyncedMotors = synchNone;
}

#endif /* _GERADEAUSFAHREN_C_ */

/*task main{

driveDistance(250);
}*/
