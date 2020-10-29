#pragma once
#pragma once
#include "glut.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include "SOIL.h"

class Lighting
{
public:
	Lighting();

	void Sunlight(GLfloat x, GLfloat y, GLfloat z, bool on);
	void Flashlight(GLfloat xP, GLfloat yP, GLfloat zP, GLfloat xD, GLfloat yD, GLfloat zD, bool on);
	void cornerLight(GLfloat xP, GLfloat yP, GLfloat zP, GLfloat xD, GLfloat yD, GLfloat zD);
	void treeLight(GLfloat xP, GLfloat yP, GLfloat zP, GLfloat xD, GLfloat yD, GLfloat zD);
protected:

private:

};