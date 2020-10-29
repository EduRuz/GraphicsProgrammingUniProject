#include "building.h"

/**
building Constructer
sets up textures.
*/
Building::Building()
{

	brickTexture = SOIL_load_OGL_texture("gfx/brick.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	carpetTexture = SOIL_load_OGL_texture("gfx/carpet.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

}

/**
Render the House made of quads.
*/
void Building::renderHouse()
{

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, brickTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	//glColor3f(6.0f, 6.0f, 6.0f);
//Exterior
glBegin(GL_QUADS);

	//Front Left- Front Face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.0f, 5.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, 0.0f);


	//Front Left - Back Face
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -0.25f);

	//Front Left - Right Face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(2.0f, 5.0f, 0.0f);

	//Front Left - Left Face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, 0.0f);

	//Front Left - Bottom Face
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.0f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -0.25f);

	//Front Left - Top Face
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 5.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.0f, 5.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -0.25f);

glEnd();

glBegin(GL_QUADS);

	//Front Middle - Front Face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(2.0f, 3.0f, 0.0f);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(3.0f, 3.0f, 0.0f);
	glTexCoord2f(0.5f, 0.4f);
	glVertex3f(3.0f, 5.0f, 0.0f);
	glTexCoord2f(0.0f, 0.4f);
	glVertex3f(2.0f, 5.0f, 0.0f);

	//Front Middle - Back Face
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(2.0f, 3.0f, -0.25f);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(3.0f, 3.0f, -0.25f);
	glTexCoord2f(0.5f, 0.4f);
	glVertex3f(3.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 0.4f);
	glVertex3f(2.0f, 5.0f, -0.25f);

	//Front Middle - Right Face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(3.0f, 3.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(3.0f, 3.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3.0f, 5.0f, 0.0f);

	//Front Middle - Left Face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(2.0f, 3.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.0f, 3.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(2.0f, 5.0f, 0.0f);

	//Front Middle - Top Face
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(2.0f, 5.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(3.0f, 5.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(2.0f, 5.0f, -0.25f);

	//Front Middle - Bottom Face
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(2.0f, 3.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(3.0f, 3.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.0f, 3.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(2.0f, 3.0f, -0.25f);

glEnd();

glBegin(GL_QUADS);

	//Front Right - Front face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3.0f, 5.0f, 0.0f);

	//Front Right - Back face
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3.0f, 5.0f, -0.25f);

	//Front Right - Right Face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, 0.0f);

	//Front Right - Left Face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3.0f, 5.0f, 0.0f);


	//Front Left - Bottom Face
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3.0f, 0.0f, -0.25f);

	//Front Left - Top Face
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(3.0f, 5.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 5.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3.0f, 5.0f, -0.25f);

glEnd();

glBegin(GL_QUADS);

	//Left - Front face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -0.25f);

	//Left - Back face
	glNormal3f(1.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25f, 5.0f, -10.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -10.25f);

	//Left - Left face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -10.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -0.25f);

	//Left - Right face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25f, 5.0f, -10.25f);

	//Left - Top face
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 5.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25f, 5.0f, -10.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -0.25f);

	//Left - Bottom face
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -0.25f);

glEnd();

glBegin(GL_QUADS);

	//Right - Front face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(4.75f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(4.75f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -0.25f);

	//Right - Back face
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(4.75f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -10.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(4.75f, 5.0f, -10.25f);

	//Right - Left face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(4.75f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(4.75f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(4.75f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(4.75f, 5.0f, -10.25f);

	//Right - Right face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -10.25f);

	//Right - Top face
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(4.75f, 5.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 5.0f, -10.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(4.75f, 5.0f, -0.25f);

	//Right - Bottom face
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(4.75f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(4.75f, 0.0f, -0.25f);

glEnd();

glBegin(GL_QUADS);
	
	//Back - Front
	//glColor3f(0.55f, 0.09f, 0.09f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -10.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -10.25f);
	//glColor3f(1.0f, 1.0f, 1.0f);

	//Back - back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -10.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -10.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -10.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -10.5f);

	//Back - Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -10.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -10.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -10.25f);

	//Back - Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -10.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -10.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -10.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -10.25f);

	//Back - Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 5.0f, -10.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 5.0f, -10.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, -10.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.0f, -10.25f);

	//Back - Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -10.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -10.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 0.0f, -10.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -10.25f);
glEnd();

glBegin(GL_QUADS);

	//Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 5.01f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 5.01f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 5.01f, -10.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 5.01f, -10.5f);


glEnd();

glBegin(GL_QUADS);
	
	//Bottom
	glColor3f(0.36f, 0.25f, 0.20f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(4.75f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(4.75f, 0.0f, -10.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25f, 0.0f, -10.25f);
	
glEnd();



glBindTexture(GL_TEXTURE_2D, NULL);

//*************************************Interior************************************************
glBegin(GL_QUADS);
	//Back
	glColor3f(0.55f, 0.09f, 0.09f);

	GLfloat jIncr = 0.112;
	GLfloat iIncr = 0.125;
	for (GLfloat i = 0; i < 5.0; i += iIncr) {
		for (GLfloat j = 0.26; j < 4.74 - jIncr; j += jIncr) {
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(j, i, -10.24);
			glVertex3f(j + jIncr, i, -10.24);
			glVertex3f(j + jIncr, i + iIncr, -10.24);
			glVertex3f(j, i + iIncr, -10.24);
		}
	}

glEnd();

glBegin(GL_QUADS);
	//Left
	glColor3f(0.75f, 0.75f, 0.75f);

	jIncr = 0.499;
	iIncr = 0.125;
	for (GLfloat i = 0; i < 5.0; i += iIncr) {
		for (GLfloat j = 0.26; j < 10.24 - jIncr; j += jIncr) {
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.27, i, -j);
			glVertex3f(0.27, i + iIncr, -j);
			glVertex3f(0.27, i + iIncr, -j - jIncr);
			glVertex3f(0.27, i, -j - jIncr);
		}
	}

glEnd();

glBegin(GL_QUADS);
//Right
	jIncr = 0.499;
	iIncr = 0.125;
	for (GLfloat i = 0; i < 5.0; i += iIncr) {
		for (GLfloat j = 0.27; j < 10.24; j += jIncr) {
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(4.73, i, -j);
			glVertex3f(4.73, i + iIncr, -j);
			glVertex3f(4.73, i + iIncr, -j - jIncr);
			glVertex3f(4.73, i, -j - jIncr);
		}
	}
glEnd();

glBegin(GL_QUADS);
//Front Left

	iIncr = 0.04975;
	jIncr = 0.125;
	for (GLfloat i = 3.0; i < 4.99 - iIncr; i += iIncr) {
		for (GLfloat j = 0.0; j < 5.0; j += jIncr) {
			glNormal3f(i, 0.0f, 1.0f);
			glVertex3f(i, j, -0.26f);
			glVertex3f(i + iIncr, j, -0.26f);
			glVertex3f(i + iIncr, j + jIncr, -0.26f);
			glVertex3f(i, j + jIncr, -0.26f);
		}
	}

glEnd();

glBegin(GL_QUADS);
//Front Middle

	iIncr = 0.025;
	jIncr = 0.025;
	for (GLfloat i = 2.0; i < 3.0; i += iIncr) {
		for (GLfloat j = 3.0; j < 5.0; j += jIncr) {
			glNormal3f(i, 0.0f, 1.0f);
			glVertex3f(i, j, -0.26f);
			glVertex3f(i + iIncr, j, -0.26f);
			glVertex3f(i + iIncr, j + jIncr, -0.26f);
			glVertex3f(i, j + jIncr, -0.26f);
		}
	}
glEnd();

glBegin(GL_QUADS);
//Front Right
	glNormal3f(0.0f, 0.0f, -1.0f);

	iIncr = 0.04975;
	jIncr = 0.125;
	for (GLfloat i = 0.01; i < 2.0 - iIncr; i += iIncr) {
		for (GLfloat j = 0.0; j < 5.0; j += jIncr) {
			glNormal3f(i, 0.0f, 1.0f);
			glVertex3f(i, j, -0.26f);
			glVertex3f(i + iIncr, j, -0.26f);
			glVertex3f(i + iIncr, j + jIncr, -0.26f);
			glVertex3f(i, j + jIncr, -0.26f);
		}
	}
glEnd();

glBegin(GL_QUADS);
//Top
	glColor3f(0.36f, 0.25f, 0.20f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.26f, 4.99f, -0.27f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(4.74f, 4.99f, -0.27f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(4.74f, 4.99f, -10.27f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.26f, 4.99f, -10.27f);


glEnd();

glBindTexture(GL_TEXTURE_2D, carpetTexture);

glBegin(GL_QUADS);
//Bottom
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.26f, 0.01f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(4.74f, 0.01f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(4.74f, 0.01f, -10.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.26f, 0.01f, -10.25f);

glEnd();

glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
glBindTexture(GL_TEXTURE_2D, NULL);
}
