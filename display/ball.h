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

extern GLfloat ballPosition[], ballPositionInitial[], ballVelocity[];
extern double ballSize, coneAngleX, coneAngleY;

void drawBall();
void drawCone();
void resetBall();
void pushBall();

#endif /* BALL_H_ */
