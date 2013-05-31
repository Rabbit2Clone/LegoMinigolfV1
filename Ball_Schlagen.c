#pragma config(Sensor, S1,     sonar,          sensorSONAR)
#pragma config(Sensor, S2,     none,           sensorNone)
#pragma config(Sensor, S3,     none,           sensorNone)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,          hitMotor,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//



void schlagen(int speed)// Vordefinierte Schlagbewegung
{

 	if(speed > 100 || speed < -100)
  {
 	 motor[hitMotor] = 0;
	}
	else
	{
		nMotorEncoder[hitMotor] = 0;
		nMotorEncoderTarget[hitMotor] = 35;
		motor[hitMotor] = speed;
		while(nMotorRunState[hitMotor] != runStateIdle)
		{

		}
		wait1Msec(1000);
		nMotorEncoder[hitMotor] = 0;
		nMotorEncoderTarget[hitMotor] = 35;
		motor[hitMotor] = -speed;
		while(nMotorRunState[hitMotor] != runStateIdle)
		{

		}

	}


}
// Die Kombination von Geschwindigkeit und Ausholbewegung erzeugt die Staerke des Schlages
// Bei einer kurzen Ausholbewegung spielt die Geschwindigkeit des Motors kaum eine Rolle

void schlagen(int speed, int range) // Einstellbare Schlagbewegung, um die Staerke des Schlages zu kontrollieren
{

 	if(speed > 100 || speed < -100)
  {

 	 writeDebugStreamLine("speed %d value is out of range", speed);

	}
	else
	{
		nMotorEncoder[hitMotor] = 0;
		nMotorEncoderTarget[hitMotor] = range;
		motor[hitMotor] = speed;
		while(nMotorRunState[hitMotor] != runStateIdle)
		{

		}
		wait1Msec(1000);
		nMotorEncoder[hitMotor] = 0;
		nMotorEncoderTarget[hitMotor] = range;
		motor[hitMotor] = -speed;
		while(nMotorRunState[hitMotor] != runStateIdle)
		{

		}

	}


}


task main()
{
 int speed = 10;
 int range = 80;

	schlagen(speed,range);

}