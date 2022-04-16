#ifndef TEXTURE_ENTITY_HPP
#define TEXTURE_ENTITY_HPP

#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
	Entity(float posX, float posY, SDL_Texture* texture);

	SDL_Rect getCurrentFrame();
	float getPosX();
	float getPosY();
	SDL_Texture* getTexture();

private:
	SDL_Rect _currentFrame;

	float _posX;
	float _posY;

	SDL_Texture* _texture;
};

#endif