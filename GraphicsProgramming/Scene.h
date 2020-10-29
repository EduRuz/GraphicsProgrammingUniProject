// Scene class. Configures a basic 3D scene.
// Interfaces with the Input class to handle user input
// Calculates and outputs Frames Per Second (FPS) rendered.
// Important functions are the constructor (initialising the scene), 
// update (for process user input and updating scene objects) and render (renders scene).
#ifndef _SCENE_H
#define _SCENE_H

// Include GLUT, openGL, input.
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include <vector>
#include "Shape.h"
#include "Camera.h"
#include "Building.h"
#include "Lighting.h"
#include "Model.h"
#include "Shadow.h"
#include "CameraPlayer.h"
#include "CameraSky.h"

class Scene{

public:
	Scene(Input *in);
	// Main render function
	void render();
	// Update function receives delta time from parent (used for frame independent updating).
	void update(float dt);
	// Resizes the OpenGL output based on new window size.
	void resize(int w, int h);

protected:
	// Renders text (x, y positions, RGB colour of text, string of text to be rendered)
	void displayText(float x, float y, float r, float g, float b, char* string);
	// A function to collate all text output in a single location
	void renderTextOutput();
	void calculateFPS();

	// draw primitive functions
	

	// For access to user input.
	Input* input;
		
	// For Window and frustum calculation.
	int width, height;
	float fov, nearPlane, farPlane;

	// For FPS counter and mouse coordinate output.
	int frame = 0, time, timebase = 0;
	char fps[40];
	char mouseText[40];

	float centerX = 400;
	float centerY = 300;

	Shape shape;
	Camera camera;
	CameraPlayer cameraP;
	CameraSky skycam;

	Building build;
	Model model;
	Model tree;
	Model skull;
	Lighting lighting;
	Lighting treeLight1;
	Lighting treeLight2;
	Lighting treeLight3;
	Lighting treeLight4;

	int camCheck;

	bool floatV;
	float floatTrack1;
	float floatTrack2;

	float shadowMatrix[16];
	float lightx;
	float lighty;
	float lightz;
	
	bool torch;
	bool checkkey;

	void solarSystem();
	float rotation;
	float rotation2;
	float rotation3;
	float sunRotation;
	float sunSpeed;
	float speed;
	float speed2;
	float speed3;

	void reflection();
	void shadows();
	void trees();
};

#endif