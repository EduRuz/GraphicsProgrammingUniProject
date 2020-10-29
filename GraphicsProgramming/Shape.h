#ifndef _SHAPE_H
#define _SHAPE_H

#include "glut.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include "SOIL.h"
#include "Model.h"

class Shape
{

	public:
		Shape();



		void renderDisk();

		void renderSphere(GLfloat longseg, GLfloat latseg, bool texture);
		void vertextAssignments(GLfloat x, GLfloat y, GLfloat z);
		void drawSphere();
		void cube();

		void plane();
		Model tree;
		GLfloat treeSpacing;

		GLuint pavingTexture;
		GLuint moonTexture;
		GLuint grassTexture;

		float sphereVerts[284];
		int vertNo = 0;

		float interval;
		float Theta;
		float d;
		float r;
		float X;
		float Y;
		
		float u;
		float v;

		const float PI = 3.1415;
		
		
};
#endif 
