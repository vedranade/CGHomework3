#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <vector>
#include <iostream>
#include <math.h>
#include "functionality.h"
#include <iostream>

using namespace std;

boolean CameraIsMoved = false;
void DrawGround();
int RotationPY = 0;
int RotationS4 = 0;
int RotationS5 = 0;

Camera::Camera()					//Sets initial camera position parameters
{
	CameraPositionX = 0.0, CameraPositionY = 0.0, CameraPositionZ = 5.0;
	CameraPointingToX = 0.0, CameraPointingToY = 0.0, CameraPointingToZ = 0.0;
	CameraTiltX = 0.0, CameraTiltY = 1.0, CameraTiltZ = 0.0;
}

Camera CamPartA;
Camera CamV2;
Camera CamV3;
Camera CamV4;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	
	glLoadIdentity();
	GenerateV2();
	GenerateV3();
	GenerateV4();
	CamPartA.PartAMoveCamera();
	//glLoadIdentity();
	
								//Draw the ground
	/*if (CameraIsMoved)
	{
		CamPartA.PartAMoveCamera();
	}*/

	glFlush();
}

void GenerateV2()
{
	glViewport(0, 0, 700, 350);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(85.0, 1.0, 1.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	CamV2.CameraPositionX = 0.0; CamV2.CameraPositionY = 14; CamV2.CameraPositionZ = 0.0;
	CamV2.CameraPointingToX = 0.0; CamV2.CameraPointingToY = 0.0; CamV2.CameraPointingToY = 0.0;
	CamV2.CameraTiltX = 0.0; CamV2.CameraTiltY = 0.0; CamV2.CameraTiltZ = -1.0;
	gluLookAt
	(
		CamV2.CameraPositionX, CamV2.CameraPositionY, CamV2.CameraPositionZ,
		CamV2.CameraPointingToX, CamV2.CameraPointingToY, CamV2.CameraPointingToY,
		CamV2.CameraTiltX, CamV2.CameraTiltY, CamV2.CameraTiltZ
	);
	GenerateObject();
	DrawGround();
}

void GenerateV3()
{
	glViewport(0, 350, 700, 350);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(85.0, 1.0, 1.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	CamV3.CameraPositionX = 10.0; CamV3.CameraPositionY = 8.0; CamV3.CameraPositionZ = 0.0;
	CamV3.CameraPointingToX = 0.0; CamV3.CameraPointingToY = 0.0; CamV3.CameraPointingToY = 0.0;
	CamV3.CameraTiltX = 0.0; CamV3.CameraTiltY = 1.0; CamV3.CameraTiltZ = 0.0;
	gluLookAt
	(
		CamV3.CameraPositionX, CamV3.CameraPositionY, CamV3.CameraPositionZ,
		CamV3.CameraPointingToX, CamV3.CameraPointingToY, CamV3.CameraPointingToY,
		CamV3.CameraTiltX, CamV3.CameraTiltY, CamV3.CameraTiltZ
	);
	GenerateObject();
	DrawGround();
}

void GenerateV4()
{
	glViewport(700, 350, 700, 350);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(85.0, 1.0, 1.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	CamV4.CameraPositionX = 0.0; CamV4.CameraPositionY = 8.0; CamV4.CameraPositionZ = 10.0;
	CamV4.CameraPointingToX = 0.0; CamV4.CameraPointingToY = 0.0; CamV4.CameraPointingToY = 0.0;
	CamV4.CameraTiltX = 0.0; CamV4.CameraTiltY = 1.0; CamV4.CameraTiltZ = 0.0;
	gluLookAt
	(
		CamV4.CameraPositionX, CamV4.CameraPositionY, CamV4.CameraPositionZ,
		CamV4.CameraPointingToX, CamV4.CameraPointingToY, CamV4.CameraPointingToY,
		CamV4.CameraTiltX, CamV4.CameraTiltY, CamV4.CameraTiltZ
	);
	GenerateObject();
	DrawGround();
}

void GenerateObject()
{
	glPushMatrix();
	glTranslatef(0.0, 7.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);											//Making the cylinder upright
	glScalef(1.0, 2.0, 1.0);
	//Draw cylinder S1
	GLUquadricObj* VerticalCylinderS1 = gluNewQuadric();
	gluQuadricDrawStyle(VerticalCylinderS1, GLU_LINE);
	gluCylinder(VerticalCylinderS1, 0.2, 0.2, 8.0, 20, 10);						//BaseRadius = 0.2, TopRadius = 0.2, Height = 8.0
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 7.5, 0);
	glScalef(1.0, 2.0, 1.0);
	//Draw sphere B2
	GLUquadricObj* SphereB2 = gluNewQuadric();
	gluQuadricDrawStyle(SphereB2, GLU_LINE);
	gluSphere(SphereB2, 0.4, 20, 10);
	glPopMatrix();
	
	glPushMatrix();
	
	glRotatef(RotationPY, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 7.5, -2.5);
	glScalef(1.0, 2.0, 1.0);
	//Draw cylinder S2 S3
	GLUquadricObj* CylinderS2S3 = gluNewQuadric();
	gluQuadricDrawStyle(CylinderS2S3, GLU_LINE);
	gluCylinder(CylinderS2S3, 0.2, 0.2, 5.0, 20, 10);
	glPopMatrix();

	glPushMatrix();
	glRotatef(RotationPY, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 7.5, -2.5);
	glScalef(1.0, 2.0, 1.0);
	//Draw sphere B1
	GLUquadricObj* SphereB1 = gluNewQuadric();
	gluQuadricDrawStyle(SphereB1, GLU_LINE);
	gluSphere(SphereB1, 0.4, 20, 10);
	glPopMatrix();

	glPushMatrix();
	glRotatef(RotationPY, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 7.5, 2.5);
	glScalef(1.0, 2.0, 1.0);
	//Draw sphere B3
	GLUquadricObj* SphereB3 = gluNewQuadric();
	gluQuadricDrawStyle(SphereB3, GLU_LINE);
	gluSphere(SphereB3, 0.4, 20, 10);
	glPopMatrix();

	glPushMatrix();
	glRotatef(RotationPY, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 7.5, 2.5);
	glRotatef(RotationPY, 0.0, 0.0, 1.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);											//Making the cylinder upright
	glScalef(1.0, 2.0, 1.0);
	//Draw cylinder S4
	GLUquadricObj* VerticalCylinderS4 = gluNewQuadric();
	gluQuadricDrawStyle(VerticalCylinderS4, GLU_LINE);
	gluCylinder(VerticalCylinderS4, 0.05, 0.2, 4.0, 20, 10);						//BaseRadius = 0.2, TopRadius = 0.2, Height = 8.0
	glPopMatrix();

	glPushMatrix();
	glRotatef(RotationPY, 0.0, 1.0, 0.0);
	
	glTranslatef(0.0, 7.5, -2.5);
	glRotatef(RotationS5, 0.0, 0.0, 1.0);
	glRotatef(270.0, 1.0, 0.0, 0.0);											//Making the cylinder upright
	glScalef(1.0, 2.0, 1.0);
	//Draw cylinder S5
	GLUquadricObj* VerticalCylinderS5 = gluNewQuadric();
	gluQuadricDrawStyle(VerticalCylinderS5, GLU_LINE);
	gluCylinder(VerticalCylinderS5, 0.05, 0.2, 4.0, 20, 10);						//BaseRadius = 0.2, TopRadius = 0.2, Height = 8.0
	glPopMatrix();

}

void Camera::reshape(int w, int h)
{
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	gluPerspective(85.0, 1.0, 1.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Camera::PartAHandleKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
			CamPartA.CameraPositionZ = CamPartA.CameraPositionZ - 0.5;
			CamPartA.CameraPointingToZ = CamPartA.CameraPointingToZ - 0.5;
			CameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 's':
			CamPartA.CameraPositionZ = CamPartA.CameraPositionZ + 0.5;
			CamPartA.CameraPointingToZ = CamPartA.CameraPointingToZ + 0.5;
			CameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 'd':
			CamPartA.CameraPointingToX = CamPartA.CameraPointingToX + 0.5;
			CamPartA.CameraPositionX = CamPartA.CameraPositionX + 0.5;
			CameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 'a':
			CamPartA.CameraPointingToX = CamPartA.CameraPointingToX - 0.5;
			CamPartA.CameraPositionX = CamPartA.CameraPositionX - 0.5;
			CameraIsMoved = true;
			glutPostRedisplay();
			break;
		case ' ':
			CamPartA.CameraPointingToY = CamPartA.CameraPointingToY + 0.5;
			CamPartA.CameraPositionY = CamPartA.CameraPositionY + 0.5;
			CameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 'c':
			CamPartA.CameraPointingToY = CamPartA.CameraPointingToY - 0.5;
			CamPartA.CameraPositionY = CamPartA.CameraPositionY - 0.5;
			CameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 'q':
			CamPartA.CameraPointingToX = CamPartA.CameraPointingToX - 0.5;
			CameraIsMoved = true;
			glutPostRedisplay();
			break;
		case 'e':
			CamPartA.CameraPointingToX = CamPartA.CameraPointingToX + 0.5;
			CameraIsMoved = true;
			glutPostRedisplay();	
			break;
		case 't':
			RotationPY += 10;
			RotationS5 -= 10;
			glutPostRedisplay();
			break;

	}
	
}

void Camera::PartAMoveCamera()
{
	//glLoadIdentity();             /* clear the matrix */
	glViewport(700, 0, 700, 350);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(85.0, 1.0, 1.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -7.5);
	glRotatef(30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 2.0, 1.0);      /* modeling transformation*/
	
	gluLookAt(
		CamPartA.CameraPositionX, CamPartA.CameraPositionY, CamPartA.CameraPositionZ,						//Camera position
		CamPartA.CameraPointingToX, CamPartA.CameraPointingToY, CamPartA.CameraPointingToZ,				//Aim at position
		CamPartA.CameraTiltX, CamPartA.CameraTiltY, CamPartA.CameraTiltZ									//Camera orientation
	);
	DrawGround();
	GLUquadricObj* quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_LINE);
	gluCylinder(quadObj, 1.5, 0.5, 6.0, 20, 10);
	
	glEnd();
}

void Camera::PartASetupCamera()
{
	glLoadIdentity();             /* clear the matrix */
	glViewport(700, 0, 700, 350);
	gluLookAt(
		CamPartA.CameraPositionX, CamPartA.CameraPositionY, CamPartA.CameraPositionZ,						//Camera position
		CamPartA.CameraPointingToX, CamPartA.CameraPointingToY, CamPartA.CameraPointingToZ,				//Aim at position
		CamPartA.CameraTiltX, CamPartA.CameraTiltY, CamPartA.CameraTiltZ									//Camera orientation
	);
	glScalef(1.0, 2.0, 1.0);      /* modeling transformation*/
	GLUquadricObj* quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_LINE);
	gluCylinder(quadObj, 4.5, 2.0, 10.0, 20, 10);
}

void DrawGround()
{
	glBegin(GL_LINES);
	for (GLfloat i = -7.5; i <= 7.5; i += 0.75) {
		glVertex3f(i, -1, 7.5);
		glVertex3f(i, -1, -7.5);
		glVertex3f(7.5, -1, i);
		glVertex3f(-7.5, -1, i);
	}
	glEnd();
}
