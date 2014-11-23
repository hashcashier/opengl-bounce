/*
 * animate.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: rami
 */

#include "animate.h"

int gameState = 0;
bool scoring = false;

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
		if(fabs(ballPosition[i]) > 0.4) {
			// Reverse velocity
			ballVelocity[i] = -ballVelocity[i];
			// detect collision
			int k = (i == 0) + (i == 0)*(ballPosition[i] < 0) + (i == 1)*3*(ballPosition[i] < 0);
			int d = (ballPosition[2] - ballPositionInitial[2])/cubeSize;
			cout << k << ' ' << d << endl;
		}

	glutPostRedisplay();

	glutTimerFunc(value, animation, value);
}

