#ifndef LABEL_HPP
#define LABEL_HPP

#include "Entity.hpp"

#include <SDL_ttf.h>
#include <string>

class Label : public Entity
{
public:
	Label(SDL_Renderer* renderer);

	void render() override;

private:
	SDL_Color _color;
	TTF_Font* _font;
	SDL_Rect _src;
	SDL_Surface* _surface;
	SDL_Texture* _texture;
};

#endif