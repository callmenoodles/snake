#define SDL_MAIN_HANDLED

#include "GameManager.h"
#include <iostream>

int main () {

	GameManager game;

	while (true) {
		game.update ();
	}

	return 0;
}