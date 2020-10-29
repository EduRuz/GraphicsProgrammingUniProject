#include "Lighting.h"

/**
Lighting constructer.
*/
Lighting::Lighting()
{

	



}

/**
Creates the directional light to replicate the sun.
@param GLfloat: X position.
@param GLfloat: Y position.
@param GLfloat: Z position.
*/
void Lighting::Sunlight(GLfloat x, GLfloat y, GLfloat z, bool on)
{	
	GLfloat Light_Diffuse0[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat Light_Position0[] = { x, y, z, 1.0f };

	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_Diffuse0);
	glLightfv(GL_LIGHT0, GL_POSITION, Light_Position0);
	glEnable(GL_LIGHT0);

	if (on == true)
	{
		glEnable(GL_LIGHT0);
	}
	else
	{
		glDisable(GL_LIGHT0);
	}
}

/**
Creates the flashlight infront of the player.
@param GLfloat: X position.
@param GLfloat: Y position.
@param GLfloat: Z position.
@param GLfloat: X direction.
@param GLfloat: y direction.
@param GLfloat: z direction.
@param bool: true to turn light on and false to turn it off.
*/
void Lighting::Flashlight(GLfloat xP, GLfloat yP, GLfloat zP, GLfloat xD, GLfloat yD, GLfloat zD, bool on)
{

	GLfloat Light_Ambient1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat Light_Diffuse1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat Light_Position1[] = { xP, yP, zP, 1.0f };
	GLfloat spot_Direction1[] = { xD, yD, zD};
	glLightfv(GL_LIGHT1, GL_AMBIENT, Light_Ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Light_Diffuse1);
	glLightfv(GL_LIGHT1, GL_POSITION, Light_Position1);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 90.0f);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_Direction1);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 50.0);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.001);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.002);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.012);

	if (on == true)
	{
		glEnable(GL_LIGHT1);
	}
	else
	{
		glDisable(GL_LIGHT1);
	}
}

/**
Creates a spotlight at the passed position and direction.
@param GLfloat: X position.
@param GLfloat: Y position.
@param GLfloat: Z position.
@param GLfloat: X direction.
@param GLfloat: y direction.
@param GLfloat: z direction.
*/
void Lighting::cornerLight(GLfloat xP, GLfloat yP, GLfloat zP, GLfloat xD, GLfloat yD, GLfloat zD)
{

	GLfloat Light_Ambient2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat Light_Diffuse2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat Light_Position2[] = { xP, yP, zP, 1.0f };
	GLfloat spot_Direction2[] = { xD, yD, zD };
	glLightfv(GL_LIGHT2, GL_AMBIENT, Light_Ambient2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Light_Diffuse2);
	glLightfv(GL_LIGHT2, GL_POSITION, Light_Position2);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 90.0f);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_Direction2);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 50.0);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.001);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.002);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.012);

	glEnable(GL_LIGHT2);

}

/**
Creates a spotlight at the passed position and direction.
@param GLfloat: X position.
@param GLfloat: Y position.
@param GLfloat: Z position.
@param GLfloat: X direction.
@param GLfloat: y direction.
@param GLfloat: z direction.
*/
void Lighting::treeLight(GLfloat xP, GLfloat yP, GLfloat zP, GLfloat xD, GLfloat yD, GLfloat zD)
{

	GLfloat Light_Ambient2[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat Light_Diffuse2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat Light_Position2[] = { xP, yP, zP, 1.0f };
	GLfloat spot_Direction2[] = { xD, yD, zD };
	glLightfv(GL_LIGHT3, GL_AMBIENT, Light_Ambient2);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, Light_Diffuse2);
	glLightfv(GL_LIGHT3, GL_POSITION, Light_Position2);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 90.0f);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_Direction2);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 50.0);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 0.001);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.002);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.012);

	glEnable(GL_LIGHT3);

}