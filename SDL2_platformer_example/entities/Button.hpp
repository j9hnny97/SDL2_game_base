#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Entity.hpp"

#include <string>

class Button : public Entity
{
public:
	Button(SDL_Renderer* renderer);

	void render() override;

private:
	SDL_Rect _src;
};

#endif