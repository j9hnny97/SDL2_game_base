
#include "WindowRenderer.hpp"

#include "../base/Logger.hpp"

WindowRenderer::WindowRenderer(const char* title, int width, int height)
	: _renderer(nullptr)
	, _window(nullptr)
{
	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (_window == nullptr)
	{
		EZ_LOG(Logger::Level::Error, "Failed to create window (" << SDL_GetError() << ")");
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED); // && SDL_RENDERER_PRESENTVSYNC);
}

void WindowRenderer::clear()
{
	SDL_RenderClear(_renderer);
}

void WindowRenderer::display()
{
	SDL_RenderPresent(_renderer);
}

void WindowRenderer::destroy()
{
	SDL_DestroyWindow(_window);
}

int WindowRenderer::getRefreshRate()
{
	SDL_DisplayMode mode;

	SDL_GetDisplayMode(SDL_GetWindowDisplayIndex(_window), 0, &mode);

	return mode.refresh_rate;
}

SDL_Renderer* WindowRenderer::getRenderer()
{
	return _renderer;
}

SDL_Texture* WindowRenderer::loadTexture(std::string const& filePath)
{
	SDL_Texture* texture = IMG_LoadTexture(_renderer, filePath.c_str());

	if (texture == nullptr)
	{
		EZ_LOG(Logger::Level::Error, "Failed to load texture " << filePath << " (" << SDL_GetError() << ")");
	}

	return texture;
}
