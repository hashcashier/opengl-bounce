/*
 * camera.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: rami
 */

#include "camera.h"

GLfloat cameraEye[3] = {-0.25, 0, 0},
		cameraCenter[3] = {0, 0, 1},
		cameraUp[3] = {0, 1, 0};

void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 640 / 480, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(cameraEye[0], cameraEye[1], cameraEye[2],
				cameraCenter[0], cameraCenter[1], cameraCenter[2],
				cameraUp[0], cameraUp[1], cameraUp[2]);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
