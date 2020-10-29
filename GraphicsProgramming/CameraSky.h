#pragma once
#include "Vector3.h"
#include "Camera.h"
class CameraSky : public Camera
{
public:
	CameraSky();

	float xD;
	float yD;
	float zD;

	float xUp;
	float yUp;
	float zUp;

	float getLookat(char);
	float getUp(char);
	float getPosition(char);

	

};