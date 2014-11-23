/*
 * display.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: rami
 */

#include "display.h"

int depth = 200, length = 10;

void displayFunction() {
	setupCamera();
	drawWalls(length, depth);
	drawBall();

	if(!gameState)
		drawCone();
	displayAngles();
	displayScores();
	displayCameraMode();
	displayGameStateText();

	glFlush();
}

