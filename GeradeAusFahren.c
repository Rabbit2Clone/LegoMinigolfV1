#pragma config(Sensor, S1,     sonar,          sensorSONAR)
#pragma config(Sensor, S2,     none,           sensorNone)
#pragma config(Sensor, S3,     none,           sensorNone)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,          hitMotor,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, encoder)

void driveDistance(int distance)
{

	distance = distance *2;			// Damit die Strecke in mm uebergeben werden kann muss der Wert hier verdoppelt werden(Experimentiell ermittelt).
	nMotorEncoder[motorB] = 0;                // reset the Motor Encoder of Motor B
	nMotorEncoder[motorC] = 0;                // reset the Motor Encoder of Motor C
	nMotorEncoderTarget[motorB] = distance;        //
	nMotorEncoderTarget[motorC] = distance;        //
	motor[motorB] = 20;                       // motor B is run at a power level of 20
	motor[motorC] = 20;

	while(nMotorRunState[motorB] != runStateIdle && nMotorRunState[motorC] != runStateIdle)
	// while Motor B AND Motor C are still running (haven't yet reached their target):
	{

	}
	motor[motorB] = 0;                       // motor B is stopped at a power level of 0
	motor[motorC] = 0;

}

task main{

driveDistance(250);
}
