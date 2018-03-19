#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <vector>
#include <iostream>
#include <math.h>
#include "functionality.h"
#include <iostream>

using namespace std;

boolean PartACameraIsMoved = false;
void DrawGround();

PartACamera::PartACamera()					//Sets initial camera position parameters
{
	CameraPositionX = 0.0, CameraPositionY = 0.0, CameraPositionZ = 5.0;
	CameraPointingToX = 0.0, CameraPointingToY = 0.0, CameraPointingToZ = 0.0;
	CameraTiltX = 0.0, CameraTiltY = 1.0, CameraTiltZ = 0.0;
}

PartACamera Cam;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	
	glLoadIdentity();
	Cam.PartAMoveCamera();
	glLoadIdentity();
	DrawGround();
								//Draw the ground
	/*if (PartACameraIsMoved)
	{
		Cam.PartAMoveCamera();
	}*/

	glFlush();
}

void PartACamera::reshape(int w, int h)
{
	
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	gluPerspective(85.0, 1.0, 1.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	
}

void PartACamera::PartAHandleKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
			Cam.CameraPositionZ = Cam.CameraPositionZ - 0.5;
			Cam.CameraPointingToZ = Cam.CameraPointingToZ - 0.5;
			PartACameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 's':
			Cam.CameraPositionZ = Cam.CameraPositionZ + 0.5;
			Cam.CameraPointingToZ = Cam.CameraPointingToZ + 0.5;
			PartACameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 'd':
			Cam.CameraPointingToX = Cam.CameraPointingToX + 0.5;
			Cam.CameraPositionX = Cam.CameraPositionX + 0.5;
			PartACameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 'a':
			Cam.CameraPointingToX = Cam.CameraPointingToX - 0.5;
			Cam.CameraPositionX = Cam.CameraPositionX - 0.5;
			PartACameraIsMoved = true;
			glutPostRedisplay();
			break;
		case ' ':
			Cam.CameraPointingToY = Cam.CameraPointingToY + 0.5;
			Cam.CameraPositionY = Cam.CameraPositionY + 0.5;
			PartACameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 'c':
			Cam.CameraPointingToY = Cam.CameraPointingToY - 0.5;
			Cam.CameraPositionY = Cam.CameraPositionY - 0.5;
			PartACameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 'q':
			Cam.CameraPointingToX = Cam.CameraPointingToX - 0.5;
			PartACameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 'e':
			Cam.CameraPointingToX = Cam.CameraPointingToX + 0.5;
			PartACameraIsMoved = true;
			glutPostRedisplay();	
			break;

	}
	
}

void PartACamera::PartAMoveCamera()
{
	//glLoadIdentity();             /* clear the matrix */
	glViewport(700, 0, 700, 350);
	glTranslatef(0.0, 0.0, -7.5);
	glRotatef(30.0, 1.0, 0.0, 0.0);
	gluLookAt(
		Cam.CameraPositionX, Cam.CameraPositionY, Cam.CameraPositionZ,						//Camera position
		Cam.CameraPointingToX, Cam.CameraPointingToY, Cam.CameraPointingToZ,				//Aim at position
		Cam.CameraTiltX, Cam.CameraTiltY, Cam.CameraTiltZ									//Camera orientation
	);
	glScalef(1.0, 2.0, 1.0);      /* modeling transformation*/
	GLUquadricObj* quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_LINE);
	gluCylinder(quadObj, 1.5, 0.5, 6.0, 20, 10);
	glEnd();
}

void PartACamera::PartASetupCamera()
{
	glLoadIdentity();             /* clear the matrix */
	glViewport(700, 0, 700, 350);
	gluLookAt(
		Cam.CameraPositionX, Cam.CameraPositionY, Cam.CameraPositionZ,						//Camera position
		Cam.CameraPointingToX, Cam.CameraPointingToY, Cam.CameraPointingToZ,				//Aim at position
		Cam.CameraTiltX, Cam.CameraTiltY, Cam.CameraTiltZ									//Camera orientation
	);
	glScalef(1.0, 2.0, 1.0);      /* modeling transformation*/
	GLUquadricObj* quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_LINE);
	gluCylinder(quadObj, 4.5, 2.0, 10.0, 20, 10);
}

void DrawGround()
{
	glBegin(GL_LINES);
	for (GLfloat i = -7.5; i <= 7.5; i += 0.25) {
		glVertex3f(i, -1, 7.5);
		glVertex3f(i, -1, -7.5);
		glVertex3f(7.5, -1, i);
		glVertex3f(-7.5, -1, i);
	}
	glEnd();
}
