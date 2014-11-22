/*
 * animate.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: rami
 */

#include "animate.h"

GLfloat ballVelocity[] = {0, 0, 0.04};
int gameState = 0;

void animation(int value) {
	if(gameState != 1)
		return;

	if(ballPosition[2] > depth*cubeSize + 1.5 - ballSize - cubeSize) {
		gameState = 2;
		return;
	}

	for(int i = 0; i < 3; i++)
		ballPosition[i] += ballVelocity[i];

	if(ballPosition[2] > depth*cubeSize + 1.5 - ballSize - cubeSize) {
		gameState = 2;
		return;
	}

	cameraEye[2] += ballVelocity[2];
	cameraCenter[2] += ballVelocity[2];

	for(int i = 0; i < 2; i++)
		if(fabs(ballPosition[i]) > 0.4)
			ballVelocity[i] = -ballVelocity[i];
//			ballPosition[i] = ballPosition[i] < 0 ? -0.4 : 0.4;
//	cout << ballVelocity[0] << ' ' << ballVelocity[1] << ' ' << ballVelocity[2] << endl;

	glutPostRedisplay();

	glutTimerFunc(16, animation, value);
}

