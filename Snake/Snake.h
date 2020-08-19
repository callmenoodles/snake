#pragma once

#include "GameObject.h"
#include <SDL.h>
#include <vector>

class Snake : public GameObject {
public:
	std::vector<SDL_Rect> body;
	SDL_Rect head;
	
	int startLength = 6;
	int size = 16;
	int spacing = 2;
	char moveDirection;
	double speed;

public:
	Snake ();

	void grow (int amount);
	void move ();
	bool collidesWith (SDL_Rect coll);
	bool hitsEdge (int SCREEN_W, int SCREEN_H);
	void reset ();

	~Snake ();
};

