
#include "Label.hpp"

Label::Label(SDL_Renderer* renderer)
	: Entity(renderer)
	, _font(TTF_OpenFont("resources/fonts/Cambria.ttc", 24))
{
	sizeX.addObserver([this](auto const& value) { _src.w = value; });
	sizeY.addObserver([this](auto const& value) { _src.h = value; });

	_color = { 255, 255, 255 };
	_surface = TTF_RenderText_Solid(_font, "TEXT", _color);
	_texture = SDL_CreateTextureFromSurface(_renderer, _surface);
}

void Label::render()
{
	if (visible.getValue())
	{
		SDL_Rect dst;
		dst.x = static_cast<int>(positionX.getValue());
		dst.y = static_cast<int>(positionY.getValue());
		dst.w = static_cast<int>(_src.w);
		dst.h = static_cast<int>(_src.h);

		SDL_RenderCopy(_renderer, _texture, NULL, &_src);
	}
}
