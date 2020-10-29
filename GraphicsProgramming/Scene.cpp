#include "Scene.h"
#include "Shape.h"
#include "Camera.h"

Scene::Scene(Input *in)
{
	// Store pointer for input class
	input = in;
		
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.53f, 0.12f, 1.0f, 1.0f);			// Cornflour Blue Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Clear stencil buffer
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	// Other OpenGL / render setting should be applied here.
	camera.update();
	cameraP.update();

	// Initialise variables
	lightx = 20.0f;
	lighty = 40.0f;
	lightz = 0.0f;

	rotation = 0.0;
	rotation2 = 1.0;
	rotation3 = 1.0;
	speed = 10.0;
	speed2 = 7.0;
	speed3 = 1.0;

	floatV = true;
	floatTrack1 = 0.0f;
	floatTrack2 = 0.0f;

	sunRotation = 1.0;
	sunSpeed = 2.0;

	camCheck = 1;

	model.load("models/teapot.obj", "gfx/crate.png");
	tree.load("models/BlueTree.obj", "gfx/BlueTree.png");
	skull.load("models/CacklingSkull.obj", "gfx/HumanSkull_sm.png");

	
}

void Scene::update(float dt)
{
	// Handle user input
	if (input->isKeyDown('e'))
	{
		switch (camCheck) {
		case 1:
			cameraP.moveCamForward(dt);
			break;
		case 0:
			camera.moveCamForward(dt);
			break;
		case 2:
			break;
		}
		
	}

	if (input->isKeyDown('d'))
	{
		switch (camCheck) {
		case 1:
			cameraP.moveCamBack(dt);
			break;
		case 0:
			camera.moveCamBack(dt);
			break;
		case 2:
			break;
		}
	}

	if (input->isKeyDown('w'))
	{
		switch (camCheck) {
		case 1:
			break;
		case 0:
			camera.moveCamUp(dt);
			break;
		case 2:
			break;
		}
		
	}

	if (input->isKeyDown('r'))
	{
		switch (camCheck) {
		case 1:
			break;
		case 0:
			camera.moveCamDown(dt);
			break;
		case 2:
			break;
		}
		
	}

	if (input->isKeyDown('s'))
	{
		switch (camCheck) {
		case 1:
			cameraP.moveCamLeft(dt);
			break;
		case 0:
			camera.moveCamLeft(dt);
			break;
		case 2:
			break;
		}
	}

	if (input->isKeyDown('f'))
	{
		switch (camCheck) {
		case 1:
			cameraP.moveCamRight(dt);
			break;
		case 0:
			camera.moveCamRight(dt);
			break;
		case 2:
			break;
		}
		camera.moveCamRight(dt);
	}

	if (input->isKeyDown('a'))
	{
		sunRotation += sunSpeed * dt;
	}


	if (input->isKeyDown('g'))
	{
		sunRotation -= sunSpeed * dt;
	}

	if (input->isKeyDown('b'))
	{
		if (torch == false) {
			torch = true;
			input->SetKeyUp('b');
		}

		else  {
			torch = false;
			input->SetKeyUp('b');
		}
	}

	if (input->isKeyDown('q'))
	{
		if (camCheck == 0) {
			camCheck++;
			glutWarpPointer(400, 300);
			glutSetCursor(GLUT_CURSOR_NONE);
		}
		else if (camCheck == 1) {
			camCheck++;
			
		}
		else if (camCheck ==2) {
			camCheck = 0;
			glutWarpPointer(400, 300);
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		}
		input->SetKeyUp('q');
	}

	if (input->isKeyDown(VK_SPACE))
	{
		if (checkkey == false) {
			glDisable(GL_LIGHTING);
			glPolygonMode(GL_FRONT, GL_LINE);
			glPolygonMode(GL_BACK, GL_LINE);
			checkkey = true;
			input->SetKeyUp(VK_SPACE);
		}

		else {
			glPolygonMode(GL_FRONT, GL_FILL);
			glPolygonMode(GL_BACK, GL_FILL);
			glEnable(GL_LIGHTING);
			checkkey = false;
			input->SetKeyUp(VK_SPACE);
		}
	}

	switch (camCheck) {
	case 0:
		camera.distX = input->getMouseX() - centerX;
		camera.distY = input->getMouseY() - centerY;

		camera.rotateCamLeft(dt);
		camera.rotateCamDown(dt);
		break;

	case 1:
		cameraP.distX = input->getMouseX() - centerX;
		cameraP.distY = input->getMouseY() - centerY;

		cameraP.rotateCamLeft(dt);
		cameraP.rotateCamDown(dt);
		break;

	case 2:
		break;
	}
	// update scene related variables.

	rotation += speed * dt;
	rotation2 += (speed2 * 2) * dt;
	rotation3 += (speed3 * 2) * dt;

	if (floatV == true) {
		floatTrack1 += 0.025;
		floatTrack2 -= 0.025;
		if (floatTrack1 > 1.0) {
			floatV = false;
		}
	}

	if (floatV == false) {
		floatTrack1 -= 0.025;
		floatTrack2 += 0.025;
		if (floatTrack1 < -1.0) {
			floatV = true;
		}
	}
	// Calculate FPS for output
	calculateFPS();
}


void Scene::render() {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera

	switch (camCheck) {
	case 2:
		gluLookAt(
			skycam.getPosition('x'), skycam.getPosition('y'),
			skycam.getPosition('z'),
			skycam.getLookat('x'), skycam.getLookat('y'),
			skycam.getLookat('z'),
			skycam.getUp('x'), skycam.getUp('y'), skycam.getUp('z'));
		break;
	case 1:
		gluLookAt(
			cameraP.getPosition('x'), cameraP.getPosition('y'),
			cameraP.getPosition('z'),
			cameraP.getLookat('x'), cameraP.getLookat('y'),
			cameraP.getLookat('z'),
			cameraP.getUp('x'), cameraP.getUp('y'), cameraP.getUp('z'));
		break;
	case 0:
		gluLookAt(
			camera.getPosition('x'), camera.getPosition('y'),
			camera.getPosition('z'),
			camera.getLookat('x'), camera.getLookat('y'),
			camera.getLookat('z'),
			camera.getUp('x'), camera.getUp('y'), camera.getUp('z'));
		break;

	}
	
	
	glPushMatrix();
	//if (sunRotation > 270 && sunRotation < 360) {
		//lighting.Sunlight(lightx, lighty, lightz, true);
	//}
	 if (sunRotation >= 0 && sunRotation < 180) {
		lighting.Sunlight(lightx, lighty, lightz, true);
	}
	else {
		lighting.Sunlight(lightx, lighty, lightz, false);
	}
	glPopMatrix();
	
	

	glPushMatrix();
		lighting.Flashlight(cameraP.getPosition('x'), cameraP.getPosition('y'),
		cameraP.getPosition('z'), cameraP.getForward('x'), cameraP.getForward('y'),
		cameraP.getForward('z'), torch);
	glPopMatrix();
	
	// Render geometry/scene here -------------------------------------
	
	glPushMatrix();
	trees();
	glPopMatrix();

	//Draw the ground
	glPushMatrix();
		glTranslatef(-25.0f, -0.01f, -25.0f);
		shape.plane();
	glPopMatrix();



	//Draw the Solar System house
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-6.25f, 0.0f, -4.0f);
		//glRotatef(90, 0.0f, 1.0f, 0.0f);
		solarSystem();
		glScalef(2.5f, 1.5f, 2.0f);
		glEnable(GL_LIGHTING);
		build.renderHouse();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-14.5f, 0.0f, 3.0f);
		glRotatef(90, 0.0f, 1.0f, 0.0f);
		reflection();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(14.5f, 0.0f, -2.0f);
		glRotatef(90, 0.0f, -1.0f, 0.0f);
		build.renderHouse();
		shadows();
		glPushMatrix();
			glTranslatef(2.5f, 2.5f, -5.0f);
			glScalef(0.5f, 0.5f, 0.5f);
			shape.renderSphere(12, 24, false);
		glPopMatrix();
		lighting.cornerLight(2.5f, 4.0f, 2.0f, 0.0f, 0.0f, -1.0f);
	glPopMatrix();

	//Draw the Sun above the plane
	glPushMatrix();
		glRotatef(sunRotation, 0.0f, 0.0f, 1.0f);
		glTranslatef(lightx, lighty, lightz);
		glColor3f(1.0f, 0.25f, 0.0f);
		glDisable(GL_LIGHTING);
		shape.renderSphere(12, 24, false);
		glEnable(GL_LIGHTING);
	glPopMatrix();
	// End render geometry --------------------------------------

	// Render text, should be last object rendered.
	renderTextOutput();
	
	// Swap buffers, after all objects are rendered.
	glutSwapBuffers();
}

// Handles the resize of the window. If the window changes size the perspective matrix requires re-calculation to match new window size.
void Scene::resize(int w, int h) 
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = (float)w / (float)h;
	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 100.0f;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(fov, ratio, nearPlane, farPlane);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);

	
}

// Calculates FPS
void Scene::calculateFPS()
{

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 1000) {
		sprintf_s(fps, "FPS: %4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
}

/**
Holds the code for the reflections inside the reflection house.
*/
void Scene::reflection()
{
	//Draw Mirror House
	//model.render(true);

glPushMatrix();
	//glScalef(2.5f, 1.5f, 2.0f);
	//build.renderHouse();

	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_ALWAYS, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	//glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);



	glBegin(GL_QUADS);
	//Back
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.76f, 1.0f, -10.22f);
	glVertex3f(4.24f, 1.0f, -10.22f);
	glVertex3f(4.24f, 4.0f, -10.22f);
	glVertex3f(0.76f, 4.0f, -10.22f);
	glEnd();

	glBegin(GL_QUADS);
	//Left
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.29f, 4.0f, -9.23f);
	glVertex3f(0.29f, 4.0f, -1.26f);
	glVertex3f(0.29f, 1.0f, -1.26f);
	glVertex3f(0.29f, 1.0f, -9.23f);

	glEnd();

	glBegin(GL_QUADS);
	//Right
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(4.71f, 1.0f, -9.23f);
	glVertex3f(4.71f, 1.0f, -1.26f);
	glVertex3f(4.71f, 4.0f, -1.26f);
	glVertex3f(4.71f, 4.0f, -9.23f);
	glEnd();

	glDisable(GL_CULL_FACE);
	//glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);


	//Back Wall Skull Reflection
	glPushMatrix();
		glScalef(1.0, 1.0, 1.0);
		glTranslatef(2.5f, 2.5f, -11.25f);
		glRotatef(rotation + 180, 0, 1, 0);
		glPushMatrix();
			glScalef(0.05f, 0.05f, 0.05f);
			skull.render(true);
		glPopMatrix();
	glPopMatrix();

	//Left Wall Skull Reflection
	glPushMatrix();
		glScalef(1.0, 1.0, 1.0);
		glTranslatef(-1.0f, 2.5f, -4.8f);
		glRotatef(rotation, 0, 1, 0);
		glPushMatrix();
			glScalef(0.05f, 0.05f, 0.05f);
			skull.render(true);
		glPopMatrix();
	glPopMatrix();

	//Right Wall Skull Reflection
	glPushMatrix();
		glScalef(1.0, 1.0, 1.0);
		glTranslatef(5.5f, 2.5f, -4.8f);
		glRotatef(rotation, 0, 1, 0);
		glPushMatrix();
			glScalef(0.05f, 0.05f, 0.05f);
			skull.render(true);
		glPopMatrix();
	glPopMatrix();
glPopMatrix();


	glDisable(GL_STENCIL_TEST);
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);


	glColor4f(0.8f, 0.8f, 1.0f, 0.8f);

	glBegin(GL_QUADS);
	//Back
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.76f, 1.0f, -10.22f);
	glVertex3f(4.24f, 1.0f, -10.22f);
	glVertex3f(4.24f, 4.0f, -10.22f);
	glVertex3f(0.76f, 4.0f, -10.22f);
	glEnd();

	glBegin(GL_QUADS);
	//Left
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.29f, 4.0f, -9.23f);
	glVertex3f(0.29f, 4.0f, -1.26f);
	glVertex3f(0.29f, 1.0f, -1.26f);
	glVertex3f(0.29f, 1.0f, -9.23f);
	glEnd();

	glBegin(GL_QUADS);
	//Right
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(4.71f, 1.0f, -9.23f);
	glVertex3f(4.71f, 1.0f, -1.26f);
	glVertex3f(4.71f, 4.0f, -1.26f);
	glVertex3f(4.71f, 4.0f, -9.23f);
	glEnd();


	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);

	build.renderHouse();
	glPushMatrix();
	glTranslatef(2.5f, 2.5f, -4.8f);
	glRotatef(rotation, 0, -1, 0);
	glPushMatrix();
		glScalef(0.05f, 0.05f, 0.05f);
		skull.render(true);
	glPopMatrix();
	glPopMatrix();

}

/**
Holds the code for the shadow inside the shadow house.
*/
void Scene::shadows()
{
	GLfloat floorVerts[] =
	{ -2.0f, -0.5f, -2.0f,
		-2.0f, -0.5f, 2.0f,
		2.0f, -0.5f, 2.0f,
		2.0, -0.5f, -2.0f
	};
	GLfloat Light_Position[] = { 2.5, 4.0, 2.0, 1.0f };

	Shadow::generateShadowMatrix(shadowMatrix, Light_Position, floorVerts);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glColor3f(0.1f, 0.1f, 0.1f); // Shadow's colour
	glPushMatrix();
		glMultMatrixf((GLfloat *)shadowMatrix);
		//translate to floor and draw shadow, remember to match any transforms on the object
		glTranslatef(2.5f, 2.5f, -1.5f);
		//glRotatef(rotation, 0.f, 1.f, 0.f);
		glScalef(0.10f, 0.10f, 0.10f);
		shape.renderSphere(12, 24, false);
	glPopMatrix();
	glColor3f(1.0f, 1.0f, 1.0f); // S
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
}

/**
Creates the tree objects
*/
void Scene::trees()
{

	glPushMatrix();
		glTranslatef(-17.5f, 0.0f, -12.5f);
		treeLight1.treeLight(0.0f, 15.0f, 0.0f, 0.0f, -1.0f, 0.0f);
		glScalef(0.0006f, 0.0006f, 0.0006f);
		tree.render(true);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(17.5f, 0.0f, -12.5f);
		treeLight2.treeLight(0.0f, 15.0f, 0.0f, 0.0f, -1.0f, 0.0f);
		glScalef(0.0006f, 0.0006f, 0.0006f);
		tree.render(true);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(17.5f, 0.0f, 12.5f);
		treeLight3.treeLight(0.0f, 15.0f, 0.0f, 0.0f, -1.0f, 0.0f);
		glScalef(0.0006f, 0.0006f, 0.0006f);
		tree.render(true);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-17.5f, 0.0f, 12.5f);
		treeLight4.treeLight(0.0f, 15.0f, 0.0f, 0.0f, -1.0f, 0.0f);
		glScalef(0.0006f, 0.0006f, 0.0006f);
		tree.render(true);
	glPopMatrix();



}

/**
Holds the code for the solar system.
*/
void Scene::solarSystem()
{
	glPushMatrix();

	glTranslatef(6.75f, 3.0f, -10.0f);

		glPushMatrix();
			 // render the Moon
			shape.renderSphere(12, 24, true);

			glPushMatrix();
				//render skull 1
				glRotatef(rotation, 0, 1, 0);
				glTranslatef(2.0f, floatTrack1, 0.0f);
				glScalef(0.05f, 0.05f, 0.05f);
				skull.render(true);
			glPopMatrix();

			glPushMatrix();
				//render skull 2
				glRotatef(rotation, 0, 1, 0);
				glTranslatef(0.0f, floatTrack2, -2.0f);
				glScalef(0.05f, 0.05f, 0.05f);
				skull.render(true);
			glPopMatrix();

			glPushMatrix(); 
				// render skull 3
				glRotatef(rotation, 0, 1, 0);
				glTranslatef(-2.0, floatTrack1, 0);
				glScalef(0.05f, 0.05f, 0.05f);
				skull.render(true);
			glPopMatrix();
			glPushMatrix();//render skull 4
				glRotatef(rotation, 0, 1, 0);
				glTranslatef(0.0, floatTrack2, 2.0f);
				glScalef(0.05f, 0.05f, 0.05f);
				skull.render(true);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

// Compiles standard output text including FPS and current mouse position.
void Scene::renderTextOutput()
{
	// Render current mouse position and frames per second.
	sprintf_s(mouseText, "Mouse: %i, %i", input->getMouseX(), input->getMouseY());
	displayText(-1.f, 0.96f, 1.f, 0.f, 0.f, mouseText);
	displayText(-1.f, 0.90f, 1.f, 0.f, 0.f, fps);
}

// Renders text to screen. Must be called last in render function (before swap buffers)
void Scene::displayText(float x, float y, float r, float g, float b, char* string) {
	// Get Lenth of string
	int j = strlen(string);

	// Swap to 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Orthographic lookAt (along the z-axis).
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Set text colour and position.
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	// Render text.
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
	// Reset colour to white.
	glColor3f(1.f, 1.f, 1.f);

	// Swap back to 3D rendering.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ((float)width/(float)height), nearPlane, farPlane);
	glMatrixMode(GL_MODELVIEW);
}
