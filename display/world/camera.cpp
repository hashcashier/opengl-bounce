/*
 * camera.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: rami
 */

#include "camera.h"

int cameraMode = 0;

GLfloat cameraEyeInitial[3] = {0, 0, 0},
		cameraCenterInitial[3] = {0, 0, 1};

GLfloat cameraEye[3] = {0, 0, 0},
		cameraCenter[3] = {0, 0, 1},
		cameraUp[3] = {0, 1, 0};

void toggleCameraMode() {
	if(cameraMode) {
		cameraUp[0] = cameraUp[2] = 0;
		cameraUp[1] = 1;
		cameraCenter[0] = cameraCenter[1] = 0;
	}
	cameraMode = 1 - cameraMode;
	glutPostRedisplay();
}

void resetCamera() {
	for(int i = 0; i < 3; i++)
		cameraEye[i] = cameraEyeInitial[i],
		cameraCenter[i] = cameraCenterInitial[i];
}

void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(cameraMode)
		gluPerspective(45, 640 / 480, 0.5, 100);
	else
		gluPerspective(45, 640 / 480, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(cameraEye[0], cameraEye[1], cameraEye[2],
				cameraCenter[0], cameraCenter[1], cameraCenter[2],
				cameraUp[0], cameraUp[1], cameraUp[2]);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
