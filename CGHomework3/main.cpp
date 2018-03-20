#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <vector>
#include <iostream>
#include <math.h>
#include "functionality.h"

using namespace std;

int window_width = 1400, window_height = 700;

void init(void) 
{ 
	glClearColor(0.0, 0.0, 0.0, 0.0);   
	glShadeModel(GL_FLAT);

}

int main(int argc, char** argv)
{ 
	Camera Cam;
	glutInit(&argc, argv);   
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   
	glutInitWindowSize(window_width, window_height);    
	glutInitWindowPosition(50, 50);   
	glutCreateWindow(argv[0]);   
	init();   
	glutDisplayFunc(display);    
	glutReshapeFunc(Cam.reshape);
	glutKeyboardFunc(Cam.PartAHandleKeyboard);
	glutMainLoop();   
	return 0; 
}