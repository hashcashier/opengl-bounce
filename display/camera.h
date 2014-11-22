/*
 * camera.h
 *
 *  Created on: Nov 22, 2014
 *      Author: rami
 */

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

using namespace std;


#ifndef CAMERA_H_
#define CAMERA_H_

extern GLfloat cameraEye[3], cameraCenter[3], cameraUp[3];
extern GLfloat cameraEyeInitial[3], cameraCenterInitial[3];

void setupCamera();
void resetCamera();

#endif /* CAMERA_H_ */
