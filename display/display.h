/*
 * display.h
 *
 *  Created on: Nov 21, 2014
 *      Author: rami
 */

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

using namespace std;

#ifndef DISPLAY_H_
#define DISPLAY_H_

extern GLfloat ballPosition[3];
extern int depth, gameState;
extern double ballSize, coneAngle;

extern void setupCamera();
extern void drawWalls(int len, int depth);
extern void drawBall();
extern void drawCone();

void displayFunction();

#endif /* DISPLAY_H_ */
