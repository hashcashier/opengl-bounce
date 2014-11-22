//============================================================================
// Name        : Graphics.cpp
// Author      : Rami Khalil
// Version     :
// Copyright   : Don't steal my code
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

#include "display/display.h"
#include "input/keyboard.h"
#include "animation/animate.h"

using namespace std;

extern void displayFunction();
extern void keyboardFunction(unsigned char c, int x, int y);
extern void keystrokeFunction(int key, int x, int y);
extern void animation(int value);

int main(int argc, char** argr) {
	srand(time(NULL));

	glutInit(&argc,argr);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 150);
	glutCreateWindow("Ball Game");
	glutDisplayFunc(displayFunction);
	glutKeyboardFunc(keyboardFunction);
	glutSpecialFunc(keystrokeFunction);
//	glutStroke
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(0,0,0,0.0);

	glutTimerFunc(16, animation, 0);

	glutMainLoop();
	return 0;
}
