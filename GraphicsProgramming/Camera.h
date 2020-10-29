#pragma once
#include "Vector3.h"
class Camera
{
public:
	Camera();
	void update();

	float distX;
	float distY;

	//Rotation Values
	float yaw;
	float pitch;
	float roll;

	//Position Values
	float Xp, Yp, Zp;

	//Vector Values
	Vector3 lookat;
	Vector3 forward;
	Vector3 up;
	Vector3 right;

	//Getters
	float getPosition(char);

	void moveCamForward(float);
	void moveCamBack(float);
	void moveCamUp(float);
	void moveCamDown(float);
	void moveCamLeft(float);
	void moveCamRight(float);

	void rotateCamLeft(float);
	void rotateCamRight(float);
	void rotateCamUp(float);
	void rotateCamDown(float);




	float getYaw();
	float getPitch();
	float getRoll();
	float getLookat(char);
	float getForward(char);
	float getUp(char);


protected:

private:

};