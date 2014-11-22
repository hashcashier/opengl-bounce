/*
 * keyboard.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: rami
 */

#include "keyboard.h"


void keyboardFunction(unsigned char c, int x, int y) {
	switch(c) {
	case ' ':
		if(gameState == 0) {
			gameState = 1;
			pushBall();
			glutTimerFunc(16, animation, 16);
		}
		break;
	case 'r':
	case 'R':
		if(gameState == 2) {
			gameState = 1;
			resetCamera();
			resetBall();
			pushBall();
			glutTimerFunc(64, animation, 64);
		}
		break;
	}
	glutPostRedisplay();
}

int dAngle = 5;
double dVelocity = 0.01;
GLfloat maxVelocity[3] = {0.05, 0.05, 0.05};

void keystrokeFunction(int key, int x, int y) {
	switch(key) {
	case GLUT_KEY_LEFT:
		if(gameState == 0) {
			coneAngleY += dAngle;
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_RIGHT:
		if(gameState == 0) {
			coneAngleY -= dAngle;
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_UP:
		if(gameState == 0) {
			coneAngleX -= dAngle;
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_DOWN:
		if(gameState == 0) {
			coneAngleX += dAngle;
			glutPostRedisplay();
		}
		break;
	}
	coneAngleX = coneAngleX < 0 ? max(coneAngleX, -85.0) : min(coneAngleX, 85.0);
	coneAngleY = coneAngleY < 0 ? max(coneAngleY, -85.0) : min(coneAngleY, 85.0);

}
