#ifndef _MOVE_TURN_C_
#define _MOVE_TURN_C_

void turn_left(int Degree)// Degree have to be multipy with 10. => 10 Degree insert 100
{

	int Degree_New = ((int)(_fGyroAngle*10) - Degree);

	motor[motorC] = -7;
  motor[motorB] = 7;

	while(((int)(_fGyroAngle*10)) > Degree_New)
	{
	}
	motor[motorC] = 0;
  motor[motorB] = 0;
	wait1Msec(100);

	while(((int)(_fGyroAngle*10)) == Degree_New)
  {
	  if((int)(_fGyroAngle*10) < Degree_New)
		{
			motor[motorC] = 2;
	  	motor[motorB] = -2;
	  	while(((int)(_fGyroAngle*10)) < Degree_New)
	  	{
	  	}
		}
		wait1Msec(100);

		if(((int)(_fGyroAngle*10)) > Degree_New)
		{
			motor[motorC] = -2;
	  	motor[motorB] = 2;
	  	while(((int)(_fGyroAngle*10)) > Degree_New)
	  	{
	  	}
		}
		wait1Msec(100);
	}
	motor[motorC] = 0;
  motor[motorB] = 0;

}

void turn_right(int Degree)// Degree have to be multipy with 10. => 10 Degree insert 100
{
	//Degree--;
	int Degree_New = (int)(_fGyroAngle*10) + Degree;

	motor[motorC] = 7;
  motor[motorB] = -7;

	while(((int)(_fGyroAngle*10)) < Degree_New)
	{
	}
	motor[motorC] = 0;
  motor[motorB] = 0;
  wait1Msec(100);

  while(((int)(_fGyroAngle*10)) == Degree_New)
  {
	  if(((int)(_fGyroAngle*10)) > Degree_New)
		{
			motor[motorC] = -2;
	  	motor[motorB] = 2;
	  	while(((int)(_fGyroAngle*10)) > Degree_New)
	  	{
	  	}
		}
		wait1Msec(100);

		if((int)(_fGyroAngle*10) < Degree_New)
		{
			motor[motorC] = 2;
	  	motor[motorB] = -2;
	  	while(((int)(_fGyroAngle*10)) < Degree_New)
	  	{
	  	}
		}
		wait1Msec(100);
	}

	motor[motorC] = 0;
  motor[motorB] = 0;

}

void turn2Degree(int Degree) // Degree have to be multipy with 10. => 10 Degree insert 100
{

	if(((int)(_fGyroAngle*10)) > Degree)
	{
		Degree++;
		motor[motorC] = -7;
		motor[motorB] = 7;
		while(((int)(_fGyroAngle*10)) > Degree)
		{
		}
	}
	else
	{
		Degree--;
		motor[motorC] = 7;
		motor[motorB] = -7;
		while(((int)(_fGyroAngle*10)) < Degree)
		{
		}
	}
	motor[motorC] = 0;
  motor[motorB] = 0;
	wait1Msec(100);

	while(((int)(_fGyroAngle*10)) == Degree)
  {
	  if((int)(_fGyroAngle*10) < Degree)
		{
			motor[motorC] = 2;
	  	motor[motorB] = -2;
	  	while(((int)(_fGyroAngle*10)) <= Degree)
	  	{
	  	}
		}
		motor[motorC] = 0;
  	motor[motorB] = 0;
		wait1Msec(100);
		if(((int)(_fGyroAngle*10)) > Degree)
		{
			motor[motorC] = -2;
	  	motor[motorB] = 2;
	  	while(((int)(_fGyroAngle*10)) >= Degree)
	  	{
	  	}
		}
		motor[motorC] = 0;
  	motor[motorB] = 0;
		wait1Msec(100);
	}
}

#endif /* _MOVE_TURN_C_ */
