#pragma once

#include <SDL.h>

class GameObject {
public:
	int x;
	int y;
	int size;
	int r, g, b, a = 255;

public:
	GameObject ();

	void draw (SDL_Renderer* renderer, SDL_Rect shape);

	~GameObject ();
};

