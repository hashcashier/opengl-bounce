/*
 * walls.h
 *
 *  Created on: Nov 22, 2014
 *      Author: rami
 */

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

using namespace std;

#ifndef WALLS_H_
#define WALLS_H_

extern double cubeSize;
extern int color[500][4][500][3], base[500][500][3], bonus[500][4][500];

void drawWalls(int len, int depth);

#endif /* WALLS_H_ */
