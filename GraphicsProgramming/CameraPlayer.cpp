#include "CameraPlayer.h"


/**
player Camera Constructor.
*/
CameraPlayer::CameraPlayer()
{
	Camera();
}

/**
Move camera forward.
@param float: value to move camera forward by.
*/
void CameraPlayer::moveCamForward(float dt)
{
	Xp += forward.x * dt;
	//Yp += forward.y * dt;
	Zp += forward.z * dt;
}

/**
Move camera backwards.
@param float: value to move camera backwards by.
*/
void CameraPlayer::moveCamBack(float dt)
{
	Xp -= forward.x * dt;
	//Yp -= forward.y * dt;
	Zp -= forward.z * dt;
}
