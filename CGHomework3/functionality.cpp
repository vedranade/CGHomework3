#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <vector>
#include <iostream>
#include <math.h>
#include "functionality.h"
#include <iostream>

using namespace std;

PartACamera Cam;

void PartACamera::PartADisplay(void)
{
	cout << " ";
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();             /* clear the matrix *

								  /* viewing transformation  */
	gluLookAt(
		Cam.CameraPositionX, Cam.CameraPositionY, Cam.CameraPositionZ,						//Camera position
		Cam.CameraPointingToX, Cam.CameraPointingToY, Cam.CameraPointingToZ,				//Aim at position
		Cam.CameraTiltX, Cam.CameraTiltY, Cam.CameraTiltZ									//Camera orientation
	);
	glScalef(1.0, 2.0, 1.0);      /* modeling transformation */
	glutWireCube(1.0);
	glFlush();
}

void PartACamera::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void PartACamera::PartAHandleKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
			Cam.CameraPositionZ = Cam.CameraPositionZ - 0.5;
			Cam.CameraPointingToZ = Cam.CameraPointingToZ - 0.5;
			glutPostRedisplay();
			break;
		case 's':
			Cam.CameraPositionZ = Cam.CameraPositionZ + 0.5;
			Cam.CameraPointingToZ = Cam.CameraPointingToZ + 0.5;
			glutPostRedisplay();
			break;
		case 'd':
			Cam.CameraPointingToX = Cam.CameraPointingToX + 0.5;
			Cam.CameraPositionX = Cam.CameraPositionX + 0.5;
			glutPostRedisplay();
			break;
		case 'a':
			Cam.CameraPointingToX = Cam.CameraPointingToX - 0.5;
			Cam.CameraPositionX = Cam.CameraPositionX - 0.5;
			glutPostRedisplay();
			break;
		case ' ':
			Cam.CameraPointingToY = Cam.CameraPointingToY + 0.5;
			Cam.CameraPositionY = Cam.CameraPositionY + 0.5;
			glutPostRedisplay();
			break;
		case 'c':
			Cam.CameraPointingToY = Cam.CameraPointingToY - 0.5;
			Cam.CameraPositionY = Cam.CameraPositionY - 0.5;
			glutPostRedisplay();
			break;
		case 'q':
			Cam.CameraPointingToX = Cam.CameraPointingToX - 0.5;
			glutPostRedisplay();
			break;
		case 'e':
			Cam.CameraPointingToX = Cam.CameraPointingToX + 0.5;
			glutPostRedisplay();
			break;

	}
	
}
