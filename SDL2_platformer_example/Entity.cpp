
#include "Entity.hpp"

Entity::Entity(SDL_Renderer* renderer)
	: positionX(0)
	, positionY(0)
	, sizeX(88)
	, sizeY(124)
	, visible(true)
	, _renderer(renderer)
{
}
