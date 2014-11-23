/*
 * walls.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: rami
 */

#include "walls.h"

double cubeSize = 0.1;
int color[500][4][500][3], base[500][500][3];

void drawWalls(int len, int depth) {
	double sx[] = {-0.5, 0.5, -0.5, -0.5};
	double sy[] = {0.5, -0.5, -0.5, -0.5};
	double dx[] = {cubeSize, 0, 0, cubeSize};
	double dy[] = {0, cubeSize, cubeSize, 0};
	double z = 1.5;

	for(int i = 0; i < depth; i++) {
		for(int k = 0; k < 4; k++) {
			double x = sx[k], y = sy[k];
			for(int j = 0; j < len; j++) {
				x += dx[k];
				y += dy[k];

				if(!color[i][k][j][0])
					for(int q = 0; q < 3; q++)
						color[i][k][j][q] = 20+rand()%200;

				glPushMatrix();
				glColor3ub(color[i][k][j][0], color[i][k][j][1], color[i][k][j][2]);
				glTranslated(x, y, z);
				glutSolidCube(cubeSize);
				glPopMatrix();
			}
		}
		z += cubeSize;
	}

	double x = 0.5, y = 0.5;
	for(int i = 0; i < len; i++, y -= cubeSize, x = 0.5)
		for(int j = 0; j < len; j++, x -= cubeSize) {
			if(!base[i][j][0])
				for(int q = 0; q < 3; q++)
					base[i][j][q] = 20+rand()%200;

			glPushMatrix();
			glColor3ub(base[i][j][0], base[i][j][1], base[i][j][2]);
			glTranslated(x, y, z);
			glutSolidCube(cubeSize);
			glPopMatrix();
		}
}


