#pragma once
#include "glut.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include "SOIL.h"

class Building
{
public:
	Building();

	void renderHouse();

	GLuint brickTexture;
	GLuint carpetTexture;
	GLuint wallpaper;



};