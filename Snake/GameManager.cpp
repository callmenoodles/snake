#include "GameManager.h"
#include <iostream>
#include <time.h>

GameManager::GameManager () {
	init ();
	srand (time (0));
}

void GameManager::init () {

	if (SDL_Init (SDL_INIT_EVERYTHING) < 0) {
		close ();
	}

	_window = SDL_CreateWindow ("Tic-Tac-Toe",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								SCREEN_W, SCREEN_H,
								SDL_WINDOW_SHOWN);

	if (_window == NULL) {
		printf ("Failed to create window: %s\n", SDL_GetError ());
		close ();
	}

	_renderer = SDL_CreateRenderer (_window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (_renderer == NULL) {
		printf ("Failed to create renderer: %s\n", SDL_GetError ());
		close ();
	}

	_texture = SDL_CreateTexture (_renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);

	if (_texture == NULL) {
		printf ("Failed to create texture: %s\n", SDL_GetError ());
		close ();
	}

	_buffer = new Uint32[SCREEN_SIZE];
	SDL_memset (_buffer, 0, SCREEN_SIZE * sizeof (Uint32));

	food.init (SCREEN_W, SCREEN_H);
	food.spawn ();
}

void GameManager::processEvents () {
	SDL_Event evnt;

	while (SDL_PollEvent (&evnt) == 1) {

		if (evnt.type == SDL_QUIT || evnt.key.keysym.sym == SDLK_ESCAPE) {
			close ();
			break;
		}

		if (evnt.type == SDL_KEYDOWN) {

			switch (evnt.key.keysym.sym) {
				case SDLK_LEFT:
					if (snake.moveDirection != 'r')
						snake.moveDirection = 'l';
					break;
				case SDLK_RIGHT:
					if (snake.moveDirection != 'l')
						snake.moveDirection = 'r';
					break;
				case SDLK_UP:
					if (snake.moveDirection != 'd')
						snake.moveDirection = 'u';
					break;
				case SDLK_DOWN:
					if (snake.moveDirection != 'u')
						snake.moveDirection = 'd';
					break;
				case SDLK_r:
					reset ();
			}
		}
	}

}

void GameManager::update () {
	processEvents ();

	for (int i = 2;i < snake.body.size ();i++) {
		
		if (snake.collidesWith (snake.body[i]) || snake.hitsEdge (SCREEN_W, SCREEN_H)) {
			move = false;
			SDL_Delay (500);
			reset ();
			break;
		}
	}

	if (move)
		snake.move ();
	
	if (snake.collidesWith (food.shape)) {
		snake.grow (1);
		food.spawn ();

		score += 100;
		std::cout << "Score: " << score << std::endl;
	}

	draw ();

	SDL_RenderPresent (_renderer);
}

void GameManager::draw () {
	SDL_RenderClear (_renderer);
	
	// Background
	SDL_SetRenderDrawColor (_renderer, 10, 10, 10, 255);
	SDL_RenderClear (_renderer);

	// Food
	SDL_SetRenderDrawColor (_renderer, 255, 0, 0, 255);
	food.draw (_renderer, food.shape);

	// Snake
	SDL_SetRenderDrawColor (_renderer, 255, 255, 255, 255);
	for (int i = 1;i < snake.body.size ();i++) {
		snake.draw (_renderer, snake.body[i]);
	}

	SDL_SetRenderDrawColor (_renderer, 0, 255, 0, 255);
	snake.draw (_renderer, snake.body[0]);

}

void GameManager::reset () {
	score = 0;
	system ("cls");
	snake.reset ();
	food.spawn ();
	move = true;
}

void GameManager::close () {
	SDL_DestroyTexture (_texture);
	SDL_DestroyRenderer (_renderer);
	SDL_DestroyWindow (_window);
	
	delete[] _buffer;
	SDL_Quit ();
	exit (1);
}

GameManager::~GameManager () {}
