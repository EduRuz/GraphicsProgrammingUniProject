#include "Camera.h"


/**
Camera Constructor.
*/
Camera::Camera()
{
	Xp = 0;
	Yp = 1.5;
	Zp = 25;
	
	yaw = 0;
	pitch = 0;
	roll = 0;

	lookat.setX(0.0);
	lookat.setY(0.0);
	lookat.setZ(0.0);

	 

}

/**
Updates the values for the camera.
*/
void Camera::update()
{
	float cosR, cosP, cosY; 
	float sinR, sinP, sinY;

	cosY = cosf(yaw*3.1415 / 180);
	cosP = cosf(pitch*3.1415 / 180);
	cosR = cosf(roll*3.1415 / 180);
	sinY = sinf(yaw*3.1415 / 180);
	sinP = sinf(pitch*3.1415 / 180);
	sinR = sinf(roll*3.1415 / 180);


	forward.x = sinY * cosP;
	forward.y = sinP;
	forward.z = cosP * -cosY;

	up.x = -cosY * sinR - sinY * sinP * cosR;
	up.y = cosP * cosR;
	up.z = -sinY * sinR - sinP * cosR * -cosY;
	
	right = up.cross(forward);

}

/**
Returns the yaw value.
*/
float Camera::getYaw()
{
	return yaw;
}

/**
Returns the pitch value.
*/
float Camera::getPitch()
{
	return pitch;
}

/**
Returns the roll value.
*/
float Camera::getRoll()
{
	return roll;
}

/**
Get the camera position dependent on the char passed in, x for the X, y for the Y, z for Z.
@param char: char for what value to return.
*/
float Camera::getPosition(char posType)
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
Move camera forward.
@param float: value to move camera forward by.
*/
void Camera::moveCamForward(float dt)
{
	Xp += forward.x * dt;
	Yp += forward.y * dt;
	Zp += forward.z * dt;
}

/**
Move camera backwards.
@param float: value to move camera backwards by.
*/
void Camera::moveCamBack(float dt)
{
	Xp -= forward.x * dt;
	Yp -= forward.y * dt;
	Zp -= forward.z * dt;
}

/**
Move camera up.
@param float: value to move camera up by.
*/
void Camera::moveCamUp(float dt)
{
	Xp -= up.x * dt;
	Yp -= up.y * dt;
	Zp -= up.z * dt;
}

/**
Move camera down.
@param float: value to move camera down by.
*/
void Camera::moveCamDown(float dt)
{
	Xp += up.x * dt;
	Yp += up.y * dt;
	Zp += up.z * dt;
}

/**
Move camera left.
@param float: value to move camera left by.
*/
void Camera::moveCamLeft(float dt) {
	
	Xp += right.x * dt;
	Yp += right.y * dt;
	Zp += right.z * dt;
}

/**
Move camera right.
@param float: value to move camera right by.
*/
void Camera::moveCamRight(float dt) {
	Xp -= right.x * dt;
	Yp -= right.y * dt;
	Zp -= right.z * dt;
}

/**
Rotate camera left.
@param float: value to rotate camera left by.
*/
void Camera::rotateCamLeft(float dt)
{
	//yaw -= 1.f;

	yaw += distX * 0.01;
	update();
}

/**
Rotate camera down.
@param float: value to rotate camera down by.
*/
void Camera::rotateCamDown(float dt)
{
	//pitch -= 1.f;
	pitch -= distY * 0.01;
	update();
}

/**
Rotate camera right.
@param float: value to rotate camera right by.
*/
void Camera::rotateCamRight(float dt)
{
	//yaw += 1.f;
	yaw += distX * 0.01;
	update();
}

/**
Rotate camera up.
@param float: value to rotate camera up by.
*/
void Camera::rotateCamUp(float dt)
{
	pitch += 1.f;
	update();
}


/**
Return the get look at value dependent on the char passed in.
@param char: char for what value to return.
*/
float Camera::getLookat(char vectorPos)
{
	
	switch (vectorPos) {
	case 'x':
		return forward.x + Xp;
		break;
	case 'y':
		return forward.y + Yp;
		break;
	case 'z':
		return forward.z + Zp;
		break;
	}

	return 0.0f;
}

/**
Return the forward value dependent on the char passed in.
@param char: char for what value to return.
*/
float Camera::getForward(char vectorPos)
{
	switch (vectorPos) {
	case 'x':
		return forward.getX();
		break;
	case 'y':
		return forward.getY();
		break;
	case 'z':
		return forward.getZ();
		break;
	}
	return 0.0f;
}

/**
Return the get up value dependent on the char passed in.
@param char: char for what value to return.
*/
float Camera::getUp(char vectorPos)
{
	switch (vectorPos) {
	case 'x':
		return up.getX();
		break;
	case 'y':
		return up.getY();
		break;
	case 'z':
		return up.getZ();
		break;
	}
	return 0.0f;
}
