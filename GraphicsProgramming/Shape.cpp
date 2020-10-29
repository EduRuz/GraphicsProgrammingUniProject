#include "shape.h"
#include <cmath>

Shape::Shape()
{
	pavingTexture = SOIL_load_OGL_texture("gfx/paving.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	grassTexture = SOIL_load_OGL_texture("gfx/grass.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	moonTexture = SOIL_load_OGL_texture("gfx/moon.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
}



/**
Render the proceduraly generated Disk.
*/
void Shape::renderDisk()
{
	Theta = 0.0f;
	interval = (2 * PI) / 20;

	r = 1;
	d = r * 2;

	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grassTexture);

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);

	for (int i = 0; i < 21; i++) {
	
		X = r*cos(Theta);
		Y = r*sin(Theta);

		u = (cos(Theta) / d) + 0.5;
		v = (sin(Theta) / d) + 0.5;

		glVertex3f(X, Y, 0.0f);
		glTexCoord2f(u,v);
		Theta += interval;
	}
	glEnd();
}

/**
Render the procudrally generated Sphere.
@param GLfloar: Number of rings.
@param GLfloat: Number of sectors.
@param bool: true to add texture, false to leave untextured.
*/
void Shape::renderSphere(GLfloat longseg, GLfloat latseg, bool texture)
{
	//ring - longitude - 12
	//sectors - latitude - 24

	vertNo = 0;
	//sphereVerts[284];

	GLfloat theta = 0.0f;
	GLfloat delta = 0.0f;
	GLfloat thetaIncr = (2 * PI) / latseg;
	GLfloat deltaIncr = (PI) / longseg;
	GLfloat x = 0.0f;
	GLfloat y = 0.0f;
	GLfloat z = 0.0f;

	GLfloat tX = 0.0;
	GLfloat tY = 0.0;

	GLfloat tXSegment = 1 / latseg;
	GLfloat tYSegment = 1 / longseg;

	if (texture == true) {
		glBindTexture(GL_TEXTURE_2D, moonTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, NULL);
	}
	glBegin(GL_QUADS);

	for (int longs = 0; longs < longseg; longs++) {
		for (int lats = 0; lats < latseg; lats++) {

			x = cosf(theta) * sinf(delta);
			y = cosf(delta);
			z = sinf(theta) * sinf(delta);

			glNormal3f(x, y, z);
			glTexCoord2f(tX, tY);
			glVertex3f(x, y, z);

			x = cosf(theta + thetaIncr) * sinf(delta);
			y = cosf(delta);
			z = sinf(theta + thetaIncr) * sinf(delta);

			glNormal3f(x, y, z);
			glTexCoord2f(tX, tY + tYSegment);
			glVertex3f(x, y, z);

			x = cosf(theta + thetaIncr) * sinf(delta + deltaIncr);
			y = cosf(delta + deltaIncr);
			z = sinf(theta + thetaIncr) * sinf(delta + deltaIncr);

			glNormal3f(x, y, z);
			glTexCoord2f(tX + tXSegment, tY + tYSegment);
			glVertex3f(x, y, z);

			x = cosf(theta) * sinf(delta + deltaIncr);
			y = cosf(delta + deltaIncr);
			z = sinf(theta) * sinf(delta + deltaIncr);

			glNormal3f(x, y, z);
			glTexCoord2f(tX + tXSegment, tY);
			glVertex3f(x, y, z);

			theta += thetaIncr;
			tX += tXSegment;

		}

		delta += deltaIncr;
		tY += tYSegment;
		tX = 0;
	}

	glEnd();

	glBindTexture(GL_TEXTURE_2D, NULL);
}

/**
Renders a basic cube out of quads.
*/
void Shape::cube()
{
	glBegin(GL_QUADS);

	//Back
	glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	//Front
	glColor3f(0.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);

	//Left
	glColor3f(0.0f, 0.0f, 1.0f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);

	//Right
	glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	//Top
	glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);

	//Bottom
	glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);

	glEnd();
}

/**
Renders a plane for a floor.
*/
void Shape::plane() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, grassTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	
	
	treeSpacing = 0;
	int gridrep[100][100];


	for (float i = 0.0f; i < 50.0f; i += 0.5f)
	{
		for (float j = 0.0f; j < 50.0f; j += 0.5f)
		{	
			
			if (j >= 0.0f && i > 20.5f && i <= 29.5) {
				glBindTexture(GL_TEXTURE_2D, pavingTexture);
			}
			else {
				glBindTexture(GL_TEXTURE_2D, grassTexture);
			}

			if (j >= 16.0f && j<= 34.0f && i <= 29.5) {
				glBindTexture(GL_TEXTURE_2D, pavingTexture);
			}

			if (j >= 23.0f && j <= 26.5f) {
				glBindTexture(GL_TEXTURE_2D, pavingTexture);
			}

			//if (j >=)
			//glBindTexture(GL_TEXTURE_2D, grassTexture);

			glBegin(GL_QUADS);
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(j, 0.0f, i);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(j, 0.0f, i + 0.5f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(j + 0.5f, 0.0f, i + 0.5f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(j + 0.5f, 0.0f, i);
			glEnd();


		}
		treeSpacing = 0;

	}
	

	glBindTexture(GL_TEXTURE_2D, NULL);
}

