#include "CameraSky.h"

/**
Fixed Sky Camera Constructor.
*/
CameraSky::CameraSky()
{
	Camera();
	Xp = 0;
	Yp = 50;
	Zp = 0;

	xD = 0;
	yD = -1;
	zD = 0;

	xUp = 0;
	yUp = 0;
	zUp = -1;
}

/**
Get the camera position dependent on the char passed in, x for the X, y for the Y, z for Z.
@param char: char for what value to return.
*/
float CameraSky::getPosition(char posType)
{
	switch (posType) {
	case 'x':
		return Xp;

		break;
	case 'y':
		return Yp;

		break;
	case 'z':

		return Zp;
		break;
	}

	return 0.0f;
}

/**
Return the get look at value dependent on the char passed in.
@param char: char for what value to return.
*/
float CameraSky::getLookat(char vectorPos)
{

	switch (vectorPos) {
	case 'x':
		return xD;
		break;
	case 'y':
		return yD;
		break;
	case 'z':
		return zD;
		break;
	}

	return 0.0f;
}

/**
Return the get up value dependent on the char passed in.
@param char: char for what value to return.
*/
float CameraSky::getUp(char vectorPos)
{
	switch (vectorPos) {
	case 'x':
		return xUp;
		break;
	case 'y':
		return yUp;
		break;
	case 'z':
		return zUp;
		break;
	}
	return 0.0f;
}