#ifndef _MATH_FUNC_C_
#define _MATH_FUNC_C_

int _distance_X2Ball = 0;
int _distance_Y2Ball = 0;

int _distance_X2Drive = 0;
int _distance_Y2Drive = 0;

const int _pos_hole_x = 460;
const int _pos_hole_y = 0;//190;

int _degree_Hit=0;

void calc_koordinaten_Ball(int Degree, unsigned int Distance)
{
	Degree /= 10;
	if(Degree >=0)
	{
		_distance_Y2Ball = (int)((float)Distance * (cosDegrees(Degree)));
		_distance_X2Ball = (int)((float)Distance * (sinDegrees(Degree)));
	}
	else
	{
		Degree *= -1;

		_distance_Y2Ball = (int)((float)Distance * (cosDegrees(Degree)));
		_distance_X2Ball = (int)((float)Distance * (sinDegrees(Degree)));
		_distance_X2Ball *= -1;
	}

	nxtDisplayStringAt(0, 16, "X:%02d Y:%02d  ",_distance_X2Ball,_distance_Y2Ball);
}

void calc_koordinaten_Drive()
{
	int preHitpositionX;
	int preHitpositionY;
	int DegreeTemp = _degree_Hit /10;



	if(_degree_Hit >= 0)
	{
		preHitpositionX = 0;
		preHitpositionY = 0;
	}
	else
	{
		DegreeTemp = _degree_Hit / -10;

		preHitpositionX = (int)(50.0 * (sinDegrees(DegreeTemp)));
		preHitpositionY = (int)(50.0 * (cosDegrees(DegreeTemp)));
	}

	_distance_X2Drive = _distance_X2Ball + preHitpositionX;
	_distance_Y2Drive = _distance_Y2Ball - preHitpositionY; //da nicht so weit zum Ball zu fahren ist

	nxtDisplayStringAt(0, 8, "DX:%02d DY:%02d  ",_distance_X2Drive,_distance_Y2Drive);

}

void calc_degree_hit(void)
{
	int distance_X_ball2hole = _pos_hole_x + _distance_X2Ball;

	int distance_Y_ball2hole =  _distance_Y2Ball - _pos_hole_y;

	_degree_Hit = (int)((atan((float)distance_Y_ball2hole/(float)distance_X_ball2hole))/PI*180.0);

	//_degree_Hit *= -10;
	nxtDisplayStringAt(50, 32, "AH: %02d",_degree_Hit);
}


#endif
