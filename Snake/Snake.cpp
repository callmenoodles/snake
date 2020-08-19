#include "Snake.h"
#include <iostream>

Snake::Snake () {
	x = 2;
	y = 2;

	moveDirection = 'r';
	grow (startLength);
} 

void Snake::grow (int amount) {
	
	for (int i = 0;i < amount;i++) {
		SDL_Rect bodypart;

		if (body.size () != 0) {

			switch (moveDirection) {
				case 'r':
					bodypart.x = body[body.size ()-1].x - size - spacing;
					bodypart.y = body[body.size ()-1].y;
					break;
				case 'l':
					bodypart.x = body[body.size ()-1].x + size + spacing;
					bodypart.y = body[body.size ()-1].y;
					break;
				case 'u':
					bodypart.x = body[body.size ()-1].x;
					bodypart.y = body[body.size ()-1].y + size + spacing;
					break;
				case 'd':
					bodypart.x = body[body.size ()-1].x;
					bodypart.y = body[body.size ()-1].y - size - spacing;
					break;
			}
		} else {
			bodypart.x = x;
			bodypart.y = y;
		}

		bodypart.w = size;
		bodypart.h = size;

		body.push_back (bodypart);
	}
}

void Snake::move () {
	SDL_Rect bodypart;

	if (body.size () != 0) {
		head = body[0];

		switch (moveDirection) {
			case 'r':
				bodypart.x = body[0].x + size + spacing;
				bodypart.y = body[0].y;
				break;
			case 'l':
				bodypart.x = body[0].x - size - spacing;
				bodypart.y = body[0].y;
				break;
			case 'u':
				bodypart.x = body[0].x;
				bodypart.y = body[0].y - size - spacing;
				break;
			case 'd':
				bodypart.x = body[0].x;
				bodypart.y = body[0].y + size + spacing;
				break;
		}
	} else {
		bodypart.x = x;
		bodypart.y = y;
	}

	bodypart.w = size;
	bodypart.h = size;

	body.pop_back ();
	body.insert (body.begin (), bodypart);
	SDL_Delay (50);
}

bool Snake::collidesWith (SDL_Rect coll) {

	if (coll.x >= body[0].x && coll.x <= body[0].x + size && coll.y >= body[0].y && coll.y <= body[0].y + size)
		return true;
	
	return false;
}

bool Snake::hitsEdge (int SCREEN_W, int SCREEN_H) {

	if (body[0].x < 0 || body[0].x > SCREEN_W - size || body[0].y < 0 || body[0].y > SCREEN_H - size)
		return true;

	return false;
}

void Snake::reset () {
	body.erase (body.begin (), body.end ());
	moveDirection = 'r';
	grow (startLength);
}

Snake::~Snake () {}
