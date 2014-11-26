/*
 * ball.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: rami
 */

#include "ball.h"

int numBalls = 1;

GLfloat ballPosition[2][3] = {{0, 0, 1.5}, {0, 0, 1.5}};
GLfloat ballPositionInitial[2][3] = {{0, 0, 1.5}, {0, 0, 1.5}};
GLfloat ballVelocity[2][3] = {{0, 0, 0.04}, {0, 0, 0.04}};

double ballSize = 0.05, coneAngleX = 0, coneAngleY = 0;

void resetBall() {
	for(int b = 0; b < numBalls; b++)
		for(int i = 0; i < 3; i++)
			ballPosition[b][i] = ballPositionInitial[b][i];
}

void pushBall() {
	ballVelocity[0][0] = 0.04*sin(PI*coneAngleY/180);
	ballVelocity[0][1] = -0.04*sin(PI*coneAngleX/180);
	ballVelocity[0][2] = 0.04*cos(PI*coneAngleY/180);
}

void drawBall() {
	for(int b = 0; b < numBalls; b++) {
		glPushMatrix();
		if(b == 1)
			glColor3ub(240, 0, 240);
		else if(currentEffect != 3)
			glColor3ub(240, 240, 240);
		else
			glColor3ub(0, 0, 0);
		glTranslated(ballPosition[b][0], ballPosition[b][1], ballPosition[b][2]);
		glutWireSphere(ballSize, 20, 20);
		glPopMatrix();
	}
}

void drawCone() {
//	cerr << coneAngle << endl;
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslated(ballPosition[0][0], ballPosition[0][1], ballPosition[0][2]);
	glRotated(coneAngleY, 0, 1, 0);
	glRotated(coneAngleX, 1, 0, 0);
//	glRotated(coneAngle+90, 0, 0, 1);
	glTranslated(0, 0, ballSize);
//	glRotated(40, 1, 0, 0);
//	glRotated(-90, 1, 0, 0);
	glutWireCone(ballSize/2, ballSize, 20, 20);
	glPopMatrix();
}

