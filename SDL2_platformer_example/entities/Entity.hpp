#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../base/Field.hpp"

#include <SDL.h>

class Entity
{
public:
	Entity(SDL_Renderer* renderer);

	virtual void render() = 0;

	Field<float> positionX;
	Field<float> positionY;
	Field<float> sizeX;
	Field<float> sizeY;
	Field<bool> visible;

protected:
	SDL_Renderer* _renderer;
};

#endif