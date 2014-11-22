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

extern GLfloat ballPosition[];
extern double ballSize, coneAngleX, coneAngleY;


void drawBall();
void drawCone();



#endif /* BALL_H_ */
