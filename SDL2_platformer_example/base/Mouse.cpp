
#include "Mouse.hpp"

Mouse::Mouse(SDL_Renderer* renderer)
	: Entity(renderer)
	, _clickedTexture(renderer, "resources/others/cursor.png", 0, 0)
	, _defaultTexture(renderer, "resources/others/cursor.png", 14, 0)
{
	SDL_ShowCursor(SDL_DISABLE);

	_clickedTexture.sizeX = 14.0f;
	_clickedTexture.sizeY = 20.0f;
	_clickedTexture.visible = false;

	_defaultTexture.sizeX = 14.0f;
	_defaultTexture.sizeY = 20.0f;
	_defaultTexture.visible = true;
}

void Mouse::processEvent(SDL_Event const& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	{
		_clickedTexture.visible = true;
		_defaultTexture.visible = false;
	}
	else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
	{
		_clickedTexture.visible = false;
		_defaultTexture.visible = true;
	}

	int positionX, positionY;
	SDL_GetMouseState(&positionX, &positionY);

	_clickedTexture.positionX = positionX;
	_clickedTexture.positionY = positionY;
	_defaultTexture.positionX = positionX;
	_defaultTexture.positionY = positionY;
}

void Mouse::render()
{
	_clickedTexture.render();
	_defaultTexture.render();
}
