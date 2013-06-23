#ifndef _SEARCH_OBJECT_C_
#define _SEARCH_OBJECT_C_


unsigned int _ObjectDistance = 0xFFFF;
int _ObjectAngle;

void searchObjekt(void)
{
	int i = 0;
	//unsigned int Measurement[140];
	turn2Degree(-700);
	wait1Msec(1000);

	nSyncedMotors = synchCB;
	nSyncedTurnRatio = -100;
	motor[motorC] = 2;
	while(((int)(_fGyroAngle*10)) < 700)
	{
		if(((int)(_fGyroAngle*10)) >= (((i+1)*10)-700))
		{
			//Measurement[i] = _Distance;

			if(_Distance < _ObjectDistance)
			{
				_ObjectDistance = _Distance; // Distance to Object
				_ObjectAngle = ((i*10)-700); // Degree of Object

					nxtDisplayStringAt(0, 32, "A:%03d   ", _ObjectAngle);
					nxtDisplayStringAt(0, 24, "D:%02dmm  ", _ObjectDistance);

			}
			i++;
			if(i>=140)
			{
				break;
			}
		}
	}
	motor[motorC] = 0;

	nSyncedTurnRatio = 100;
	nxtDisplayStringAt(0, 32, "A:%03d   ", _ObjectAngle);
	nxtDisplayStringAt(0, 24, "D:%02dmm  ", _ObjectDistance);
}


#endif /* _SEARCH_OBJECT_C_ */
