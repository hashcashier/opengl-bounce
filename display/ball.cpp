/*
 * ball.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: rami
 */

#include "ball.h"

GLfloat ballPosition[3] = {0, 0, 1.5};
double ballSize = 0.05, coneAngleX = 0, coneAngleY = 0;

void drawBall() {
	glPushMatrix();
	glColor3ub(240, 240, 240);
	glTranslated(ballPosition[0], ballPosition[1], ballPosition[2]);
	glutWireSphere(ballSize, 20, 20);
	glPopMatrix();
}

void drawCone() {
//	cerr << coneAngle << endl;
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslated(ballPosition[0], ballPosition[1], ballPosition[2]);
	glRotated(coneAngleY, 0, 1, 0);
	glRotated(coneAngleX, 1, 0, 0);
//	glRotated(coneAngle+90, 0, 0, 1);
	glTranslated(0, 0, ballSize);
//	glRotated(40, 1, 0, 0);
//	glRotated(-90, 1, 0, 0);
	glutWireCone(ballSize/2, ballSize, 20, 20);
	glPopMatrix();
}

