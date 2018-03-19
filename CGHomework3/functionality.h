#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <vector>
#include <iostream>
#include <math.h>

class PartACamera
{
	public:
	GLdouble CameraPositionX, CameraPositionY, CameraPositionZ;				
	GLdouble CameraPointingToX, CameraPointingToY, CameraPointingToZ;			//All zeroes : the camera is pointing to origin
	GLdouble CameraTiltX, CameraTiltY, CameraTiltZ;							//Y = 1 : camera is in horizontal, usual position

	//static void PartADisplay(void);
	static void reshape(int w, int h);
	static void PartAHandleKeyboard(unsigned char key, int x, int y);
	static void PartAMoveCamera();
	static void PartASetupCamera();
	PartACamera();
};

void display(void);