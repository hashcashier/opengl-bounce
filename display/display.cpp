/*
 * display.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: rami
 */

#include "display.h"

int depth = 200;

void displayFunction() {
	setupCamera();
	drawWalls(10, depth);
	drawBall();

	if(!gameState)
		drawCone();

	glFlush();
}

