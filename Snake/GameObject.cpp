#include "GameObject.h"

GameObject::GameObject () {}

void GameObject::draw (SDL_Renderer* renderer, SDL_Rect shape) {
	SDL_RenderFillRect (renderer, &shape);
}

GameObject::~GameObject () {}
