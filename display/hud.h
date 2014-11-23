/*
 * hud.h
 *
 *  Created on: Nov 23, 2014
 *      Author: rami
 */

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

using namespace std;

#ifndef HUD_H_
#define HUD_H_

extern double coneAngleX, coneAngleY;
extern GLfloat cameraEye[3], cameraCenter[3], cameraUp[3];
extern int score, scoreLast, scoreRound, cameraMode, gameState;

void displayAngles();
void printText(double x, double y, string text, int r, int g, int b);
void displayScores();
void displayCameraMode();
void displayGameStateText();


#endif /* HUD_H_ */
