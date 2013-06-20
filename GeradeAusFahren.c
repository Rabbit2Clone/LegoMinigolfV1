/*#pragma config(Sensor, S1,     sonar,          sensorSONAR)
#pragma config(Sensor, S2,     none,           sensorNone)
#pragma config(Sensor, S3,     none,           sensorNone)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,          hitMotor,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, encoder)*/

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
		motor[motorB] = 7;                       // motor B is run at a power level of 20
		//motor[motorC] = 15;

		while(nMotorRunState[motorB] != runStateIdle)// && nMotorRunState[motorC] != runStateIdle)
		// while Motor B AND Motor C are still running (haven't yet reached their target):
		{
			EndTimeSlice();
		}
		motor[motorB] = 0;
		if(((int)_fGyroAngle- fAngleDrive) >= 1) // Fahrkorrektur
		{
			turn_left(10);
			//nxtDisplayStringAt(62, 48, "  %3d Grad   ", (int)_fGyroAngle);
		}
		else if(((int)_fGyroAngle- fAngleDrive) <= -1)
		{
			turn_right(10);
			//nxtDisplayStringAt(62, 48, "  %3d Grad   ", (int)_fGyroAngle);
		}
		motor[motorB] = 0;                       // motor B is stopped at a power level of 0
		//motor[motorC] = 0;
	}
	nSyncedMotors = synchNone;
}

#endif /* _GERADEAUSFAHREN_C_ */

/*task main{

driveDistance(250);
}*/
