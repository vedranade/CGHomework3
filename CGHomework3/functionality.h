#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <vector>
#include <iostream>
#include <math.h>

class PartACamera
{
	public:
	GLdouble CameraPositionX = 0.0, CameraPositionY = 0.0, CameraPositionZ = 3.0;				
	GLdouble CameraPointingToX = 0.0, CameraPointingToY = 0.0, CameraPointingToZ = 0.0;			//All zeroes : the camera is pointing to origin
	GLdouble CameraTiltX = 0.0, CameraTiltY = 1.0, CameraTiltZ = 0.0;							//Y = 1 : camera is in horizontal, usual position

	static void PartADisplay(void);
	static void reshape(int w, int h);
	static void PartAHandleKeyboard(unsigned char key, int x, int y);
};

