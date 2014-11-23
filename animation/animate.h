/*
 * animate.h
 *
 *  Created on: Nov 21, 2014
 *      Author: rami
 */

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

using namespace std;

#ifndef ANIMATE_H_
#define ANIMATE_H_

void animate(int value);
extern GLfloat cameraEye[3], cameraCenter[3], cameraUp[3];
extern GLfloat ballVelocity[3], ballPosition[3], ballPositionInitial[3];
extern int color[500][4][500][3], base[500][500][3];
extern int gameState, depth, score, scoreLast, scoreRound, cameraMode;
extern double cubeSize, ballSize;
extern bool scoring;

#endif /* ANIMATE_H_ */
