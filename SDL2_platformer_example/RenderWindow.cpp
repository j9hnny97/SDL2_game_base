
#include "RenderWindow.hpp"

#include <iostream>

RenderWindow::RenderWindow(const char* title, int width, int height)
	: _renderer(nullptr)
	, _window(nullptr)
{
	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (_window == nullptr)
	{
		std::cout << "Failed to create window (" << SDL_GetError() << ", " << title << ")" << std::endl;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED); // && SDL_RENDERER_PRESENTVSYNC);
}

void RenderWindow::clear()
{
	SDL_RenderClear(_renderer);

}

void RenderWindow::display()
{
	SDL_RenderPresent(_renderer);
}

void RenderWindow::destroy()
{
	SDL_DestroyWindow(_window);
}

int RenderWindow::getRefreshRate()
{
	SDL_DisplayMode mode;

	SDL_GetDisplayMode(SDL_GetWindowDisplayIndex(_window), 0, &mode);

	return mode.refresh_rate;
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
	SDL_Texture* texture = IMG_LoadTexture(_renderer, filePath);

	if (texture == nullptr)
	{
		std::cout << "Failed to load texture (" << SDL_GetError() << ", " << filePath << ")" << std::endl;
	}

	return texture;
}

void RenderWindow::render(Entity& entity)
{
	SDL_Rect src;
	src.x = entity.getCurrentFrame().x;
	src.y = entity.getCurrentFrame().y;
	src.w = entity.getCurrentFrame().w;
	src.h = entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = static_cast<int>(entity.getPosX() * 1);
	dst.y = static_cast<int>(entity.getPosY() * 1);
	dst.w = entity.getCurrentFrame().w * 1;
	dst.h = entity.getCurrentFrame().h * 1;

	SDL_RenderCopy(_renderer, entity.getTexture(), &src, &dst);
}
