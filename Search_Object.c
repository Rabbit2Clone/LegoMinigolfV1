#ifndef _SEARCH_OBJECT_C_
#define _SEARCH_OBJECT_C_


unsigned int _ObjectDistance = 0xFFFF;
int _ObjectAngle;

void searchObjekt(void)
{
	int i = 0;
	unsigned int Measurement[140];
	turn2Degree(-700);
	wait1Msec(1000);
	/*
	for(i=0;i<140;i++)
	{
		turn2Degree((i*10)-700);
		wait1Msec(70);

		Measurement[i] = _Distance;

		if(Measurement[i] < _ObjektDistance[1])
		{
			_ObjektDistance[1] = Measurement[i]; // Distance to Object
			_ObjektDistance[0] = ((i*10)-700); // Degree of Object
		}
	}

	wait1Msec(200);
	turn2Degree(_ObjektDistance[0]);
	wait1Msec(200);
	driveDistance(_ObjektDistance[1]);*/

	nSyncedMotors = synchCB;
	nSyncedTurnRatio = -100;
	motor[motorC] = 2;
	//motor[motorB] = -7;
	while(((int)(_fGyroAngle*10)) < 700)
	{
		if(((int)(_fGyroAngle*10)) >= (((i+1)*10)-700))
		{
			Measurement[i] = _Distance;

			if(Measurement[i] < _ObjectDistance)
			{
				_ObjectDistance = Measurement[i]; // Distance to Object
				_ObjectAngle = ((i*10)-700); // Degree of Object
			}
			i++;
			if(i>=140)
				break;
		}
	}
	motor[motorC] = 0;

	//wait1Msec(100);

	nSyncedTurnRatio = 100;
	nxtDisplayStringAt(62, 48, "  %03d   ", _ObjectAngle);
	nxtDisplayStringAt(62, 24, "  %02dmm  ", _ObjectDistance);
	wait1Msec(200);
	turn2Degree(_ObjectAngle);
	wait1Msec(200);
	driveDistance(_ObjectDistance);
	wait1Msec(200);
	schlagen(20,80);

}


#endif /* _SEARCH_OBJECT_C_ */
