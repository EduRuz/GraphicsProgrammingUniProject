#pragma once
#include "Vector3.h"
#include "Camera.h"
class CameraPlayer: public Camera
{
public:
	CameraPlayer();

	void moveCamForward(float);
	void moveCamBack(float);

};