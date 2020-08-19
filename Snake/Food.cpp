#include "Food.h"
#include <iostream>
#include <time.h>

Food::Food () {
	srand (time (0));
}

void Food::init (int SCREEN_W, int SCREEN_H) {
	size = 8;

	for (int x = 2;x < SCREEN_W - size;x += 18) {
		for (int y = 2;y < SCREEN_H - size;y += 18) {
			xPositions.push_back (x);
			yPositions.push_back (y);
		}
	}
}


void Food::spawn () {
	int random = rand () % (xPositions.size ()-1);

	x = xPositions[random] + size/2;
	y = yPositions[random] + size/2;

	shape = {x, y, size, size};
}

Food::~Food () {}
