#pragma once

#include "GameObject.h"
#include <vector>

class Food : public GameObject {
public:
	SDL_Rect shape;
	std::vector<int> xPositions;
	std::vector<int> yPositions;

public:
	Food ();

	void init (int SCREEN_W, int SCREEN_H);
	void spawn ();

	~Food ();
};

