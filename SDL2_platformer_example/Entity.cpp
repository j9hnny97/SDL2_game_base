
#include "Entity.hpp"

Entity::Entity(float posX, float posY, SDL_Texture* texture)
	: _posX(posX)
	, _posY(posY)
	, _texture(texture)
{
	_currentFrame.x = 0;
	_currentFrame.y = 0;
	_currentFrame.w = 88;
	_currentFrame.h = 124;
}

SDL_Rect Entity::getCurrentFrame()
{
	return _currentFrame;
}

float Entity::getPosX()
{
	return _posX;
}

float Entity::getPosY()
{
	return _posY;
}

SDL_Texture* Entity::getTexture()
{
	return _texture;
}
