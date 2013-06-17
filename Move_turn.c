#ifndef _MOVE_TURN_C_
#define _MOVE_TURN_C_

void turn_left(unsigned int Degree)
{
	signed int Degree_New = _fGyroAngle - Degree;

	motor[motorC] = -7;
  motor[motorB] = 7;

	while(_fGyroAngle > Degree_New)
	{

	}

	/*motor[motorC] = 8;
  motor[motorB] = -8;

	while(_fGyroAngle <= Degree_New)
	{

	}*/
	motor[motorC] = 0;
  motor[motorB] = 0;

}

void turn_right(unsigned int Degree)
{
	signed int Degree_New = _fGyroAngle + Degree;

	motor[motorC] = 7;
  motor[motorB] = -7;

	while(_fGyroAngle < Degree_New)
	{

	}

	/*motor[motorC] = -8;
  motor[motorB] = 8;

	while(_fGyroAngle >= Degree_New)
	{

	}*/
	motor[motorC] = 0;
  motor[motorB] = 0;

}

#endif /* _MOVE_TURN_C_ */
