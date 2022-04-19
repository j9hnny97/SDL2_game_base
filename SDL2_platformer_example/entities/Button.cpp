
#include "Button.hpp"

Button::Button(SDL_Renderer* renderer)
	: Entity(renderer)
{
	sizeX.addObserver([this](auto const& value) { _src.w = value; });
	sizeY.addObserver([this](auto const& value) { _src.h = value; });
}

void Button::render()
{
	if (visible.getValue())
	{
		SDL_Rect dst;
		dst.x = static_cast<int>(positionX.getValue());
		dst.y = static_cast<int>(positionY.getValue());
		dst.w = static_cast<int>(_src.w);
		dst.h = static_cast<int>(_src.h);
	}
}
