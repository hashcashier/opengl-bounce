/*
 * animate.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: rami
 */

#include "animate.h"

int gameState = 0, score = 0, scoreLast = 0, scoreRound = 0, currentEffect = 0;
bool scoring = false;

void animation(int value) {
	if(gameState != 1)
		return;

	if(ballPosition[2] > depth*cubeSize + 1.5 - ballSize - cubeSize) {
		if(scoring)
			score += scoreRound;
		gameState = 2;
		glutPostRedisplay();
		return;
	}

	for(int i = 0; i < 3; i++)
		ballPosition[i] += ballVelocity[i]/value;

	if(ballPosition[2] > depth*cubeSize + 1.5 - ballSize - cubeSize) {
		if(scoring)
			score += scoreRound;
		gameState = 2;
		glutPostRedisplay();
		return;
	}

	cameraEye[2] += ballVelocity[2]/value;
	cameraCenter[2] += ballVelocity[2]/value;

	if(cameraMode) {
		for(int i = 0; i < 2; i++)
			cameraCenter[i] = ballPosition[i];
	}

	for(int i = 0; i < 2; i++)
		if(fabs(ballPosition[i]) > 0.4) {
			// Reverse velocity
			ballVelocity[i] = -ballVelocity[i];
			// detect collision
			int k = (i == 0) + (i == 0)*(ballPosition[i] < 0) + (i == 1)*3*(ballPosition[i] < 0);
			int d = (ballPosition[2] - ballPositionInitial[2])/cubeSize;
			int j = ballPosition[(i+1)%2]*10 + 5;
//			cout << k << ' ' << d << ' ' << j << endl;
			scoreLast = (color[d][k][j][0]-color[d][k][j][1])*max(1, color[d][k][j][2]/40);

			if(bonus[d][k][j])
				currentEffect = bonus[d][k][j];

			if(currentEffect == 1)
				scoreRound += 3*scoreLast;
			else if(currentEffect != 4)
				scoreRound += scoreLast;

			switch(currentEffect) {
			case 1: // 3X Score
				break;
			case 2: // two balls
				break;
			case 3: // black ball
				break;
			case 4: // doomed
				break;
			}
		}

	glutPostRedisplay();

	glutTimerFunc(16, animation, value);
}

