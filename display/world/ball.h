/*
 * ball.h
 *
 *  Created on: Nov 22, 2014
 *      Author: rami
 */

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

using namespace std;

#ifndef BALL_H_
#define BALL_H_

#define PI 3.14159265

extern GLfloat ballPosition[2][3], ballPositionInitial[2][3], ballVelocity[2][3];
extern double ballSize, coneAngleX, coneAngleY;
extern int currentEffect, numBalls;

void drawBall();
void drawCone();
void resetBall();
void pushBall();

#endif /* BALL_H_ */
