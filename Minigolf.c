#pragma config(Sensor, S1,     MSDIST,              sensorI2CCustomFastSkipStates9V)
#pragma config(Sensor, S2,     none,          sensorNone)
#pragma config(Sensor, S3,     none,          sensorNone)
#pragma config(Sensor, S4,     HTGYRO,          sensorAnalogInactive)
#pragma config(Motor,  motorA,          hitMotor,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, encoder)
//#pragma config(Sensor, S1,     sonar,          sensorSONAR) // OLD DRIVER "Distance_read.c"
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define _Minigolf


//const tSensors kGyroSensor = S4;      // Connect to port 3. Adjust as appropriate.

//#include "Distance_read.c"
#include "DistDriver.c"
#include "GyroDriver.c"
#include "Move_turn.c"
#include "GeradeAusFahren.c"
#include "Ball_Schlagen.c"
#include "Search_Object.c"

task main()
{
	//float fOldAngle = -1;
	//int iOldDistance = 0xFF;
	//unsigned int i;

	//unsigned int scannedDist[180];

	eraseDisplay();
	//Dist_PowerOn();
	wait1Msec(11);


	nxtDisplayStringAt(0, 63, "Minigolf 2013");

	nxtDisplayStringAt(0, 48, "GyroSensor:");
	nxtDisplayStringAt(0, 40, "SonarSensor:");

	nxtDisplayStringAt(0, 32, "Angle to Ball:");
	nxtDisplayStringAt(0, 24, "Distance to Ball:");

	wait1Msec(1000);

	//while (!bIsGyroInitialized())

	while(!_GyrodriverInitFinish) // Gyro initialisierung
	{
		EndTimeSlice();
	}

	/*for(i=0;i<180;i++)
	{

	int sonarValue = GetDistance();
	if( sonarValue !=	iOldDistance)
	{
	nxtDisplayStringAt(62, 39, "  %2dmm   ", (long) sonarValue);
	iOldDistance = sonarValue;
	scannedDist[i] = sonarValue;
	}

	if (_fGyroAngle != fOldAngle)
	{
	nxtDisplayStringAt(62, 48, "  %3d Grad   ", (long)_fGyroAngle);
	fOldAngle = _fGyroAngle;
	}
	//turn_right(1);
	wait1Msec(200);
	}*/



	/*while(1)
	{
	//int sonarValue = GetDistance();
	int sonarValue = GetDistanceRead();
	if( sonarValue !=	iOldDistance)
	{
	nxtDisplayStringAt(62, 39, "  %2dmm   ", (long) sonarValue);
	iOldDistance = sonarValue;
	}

	if (_fGyroAngle != fOldAngle)
	{
	nxtDisplayStringAt(62, 48, "  %3d Grad   ", (long)_fGyroAngle);
	fOldAngle = _fGyroAngle;
	}
	wait1Msec(100);
	//turn_left(10);
	}*/
	/*
	iOldDistance = GetDistanceRead();
	nxtDisplayStringAt(62, 39, "  %2dmm   ", (int) iOldDistance);

	while(iOldDistance > 150)
	{
	driveDistance(iOldDistance-150);
	wait1Msec(200);
	iOldDistance = GetDistanceRead();
	nxtDisplayStringAt(62, 39, "  %2dmm   ", (int) iOldDistance);
	}
	wait1Msec(200);
	iOldDistance = GetDistanceRead();
	if(iOldDistance < 150)
	{
	wait1Msec(200);
	iOldDistance = GetDistanceRead();
	}

	nxtDisplayStringAt(62, 39, "  %2dmm   ", (int) iOldDistance);
	nxtDisplayStringAt(62, 48, "  %3d Grad   ", (int)_fGyroAngle);
	turn_left(900);
	nxtDisplayStringAt(62, 48, "  %3d Grad   ", (int)_fGyroAngle);
	wait1Msec(200);
	driveDistance(55);
	wait1Msec(200);
	turn_right(900);
	nxtDisplayStringAt(62, 48, "  %3d Grad   ", (int)_fGyroAngle);
	wait1Msec(200);
	driveDistance(iOldDistance);
	wait1Msec(200);
	schlagen(20,80);*/

	//searchObjekt();
	//driveDistance(300);
	while(1)
	{
		//EndTimeSlice();

		nxtDisplayStringAt(62, 48, "  %03d   ", (int)_fGyroAngle);
		turn2Degree(0);
		wait10Msec(10);
	}
	//Dist_PowerOff();
	StopAllTasks();
}
