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

	if(ballPosition[0][2] > depth*cubeSize + 1.5 - ballSize - cubeSize) {
		if(scoring)
			score += scoreRound;
		gameState = 2;
		glutPostRedisplay();
		return;
	}

	for(int b = 0; b < numBalls; b++)
		for(int i = 0; i < 3; i++)
			ballPosition[b][i] += ballVelocity[b][i]/value;

	if(ballPosition[0][2] > depth*cubeSize + 1.5 - ballSize - cubeSize) {
		if(scoring)
			score += scoreRound;
		gameState = 2;
		glutPostRedisplay();
		return;
	}

	cameraEye[2] += ballVelocity[0][2]/value;
	cameraCenter[2] += ballVelocity[0][2]/value;

	if(cameraMode) {
		for(int i = 0; i < 2; i++)
			cameraCenter[i] = ballPosition[0][i];
	}

	for(int b = 0; b < numBalls; b++)
		for(int i = 0; i < 2; i++)
			if(fabs(ballPosition[b][i]) > 0.4) {
				// Reverse velocity
				ballVelocity[b][i] = -ballVelocity[b][i];
				// detect collision
				int k = (i == 0) + (i == 0)*(ballPosition[b][i] < 0) + (i == 1)*3*(ballPosition[b][i] < 0);
				int d = (ballPosition[b][2] - ballPositionInitial[b][2])/cubeSize;
				int j = ballPosition[b][(i+1)%2]*10 + 5;
	//			cout << k << ' ' << d << ' ' << j << endl;
				scoreLast = (color[d][k][j][0]-color[d][k][j][1])*max(1, color[d][k][j][2]/40);

				int effect = bonus[d][k][j]*(currentEffect != 3);

				if(effect == 2 && effect != currentEffect) {
					numBalls = 2;
					for(int j = 0; j < 2; j++)
						ballPosition[1][j] = 0;//ballPosition[0][j];
					ballPosition[1][2] = ballPosition[0][2];

					ballVelocity[1][0] = ballVelocity[0][0]/2;
					ballVelocity[1][1] = ballVelocity[0][1]/2;
					ballVelocity[1][2] = ballVelocity[0][2];
				} else if(effect && effect != 2)
					numBalls = 1;

				if(effect)
					currentEffect = effect;

				if(currentEffect == 1)
					scoreRound += 3*scoreLast;
				else if(currentEffect != 4)
					scoreRound += scoreLast;
			}

	glutPostRedisplay();

	glutTimerFunc(16, animation, value);
}

