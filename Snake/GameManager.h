#pragma once

#include "Snake.h"
#include "Food.h"
#include <SDL.h>

class GameManager {
public:
	const static int SCREEN_W = 794;
	const static int SCREEN_H = 597;
	const static int SCREEN_SIZE = SCREEN_W * SCREEN_H;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	SDL_Texture* _texture;
	Uint32* _buffer;

	Snake snake;
	Food food;

	bool move = true;
	int score = 0;

public:
	GameManager ();

	void init ();
	void processEvents ();
	void update ();
	void draw ();
	void reset ();
	void close ();

	~GameManager ();
};