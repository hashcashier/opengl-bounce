/*
 * keyboard.h
 *
 *  Created on: Nov 21, 2014
 *      Author: rami
 */

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

using namespace std;

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

void keyboardFunction(unsigned char c, int x, int y);
void keystrokeFunction(int key, int x, int y);

extern void animation(int value);
extern void resetCamera();
extern void resetBall();
extern void pushBall();
extern void toggleCameraMode();

extern int gameState, scoreRound, roundNumber;
extern double coneAngleX, coneAngleY;
extern bool scoring;


#endif /* KEYBOARD_H_ */
