/*
 * hud.cpp
 *
 *  Created on: Nov 23, 2014
 *      Author: rami
 */

#include "hud.h"

int roundNumber = 1;

void displayAngles() {
	ostringstream ossA, ossB;
	ossA << "YZ-Plane Angle: " << coneAngleY;
	printText(0.4, 0.4, ossA.str(), 255, 255, 0);
	ossB << "XZ-Plane Angle: " << coneAngleX;
	printText(0.4, 0.35, ossB.str(), 255, 255, 0);
}

void displayScores() {
	ostringstream ossA, ossB, ossC;
	ossA << "Total Score: " << score;
	ossB << "Round " << roundNumber << " Score: " << scoreRound;
	ossC << "Last Score: " << scoreLast;
	printText(0.4, 0.3, ossA.str(), 255, 255, 0);
	printText(0.4, 0.25, ossB.str(), 255, 255, 0);
	printText(0.4, 0.2, ossC.str(), 255, 255, 0);
}

void displayCameraMode() {
	string mode = "Simple";
	if(cameraMode == 1) {
		mode = "Enhanced";
	}
	printText(0.4, 0.15, mode + " Camera Mode", 255, 255, 0);
}

void displayGameStateText() {
	string text = "";

	if(gameState == 0) {
		text = "Use arrows to aim. Press Space to launch.";
	} else if(gameState == 1) {
		text = "Press C to toggle camera mode.";
	} else {
		text = "Press R to replay. Press N to go to the next round.";
	}
	printText(0.4, 0.1, text, 255, 255, 0);
}

void displayBonusText() {
	string bonusText = "";
	switch (currentEffect) {
	case 1:
		bonusText = "3X Score";
		break;
	case 2:
		bonusText = "Two Balls";
		break;
	case 3:
		bonusText = "Black Ball";
		break;
	case 4:
		bonusText = "Doomed (No Score)";
		break;
	}
	if(bonusText != "")
		printText(0.4, 0.05, bonusText, 255, 0, 255);
}

void printText(double x, double y, string text, int r = 255, int g = 255, int b = 255) {
	glColor3ub(r, g, b);
	glRasterPos3f(x, y, cameraCenter[2]+0.1);
	for(int i = 0; i < (int) text.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
}
