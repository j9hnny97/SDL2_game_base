
#include "WindowRenderer.hpp"

#include "Logger.hpp"

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

SDL_Texture* WindowRenderer::loadTexture(std::string const& filePath)
{
	SDL_Texture* texture = IMG_LoadTexture(_renderer, filePath.c_str());

	if (texture == nullptr)
	{
		EZ_LOG(Logger::Level::Error, "Failed to load texture " << filePath << " (" << SDL_GetError() << ")");
	}

	return texture;
}

void WindowRenderer::render(Entity& entity)
{
	auto const& currentFrame = entity.getCurrentFrame();

	SDL_Rect src;
	src.x = currentFrame.x;
	src.y = currentFrame.y;
	src.w = currentFrame.w;
	src.h = currentFrame.h;

	SDL_Rect dst;
	dst.x = static_cast<int>(entity.getPosX() * 1);
	dst.y = static_cast<int>(entity.getPosY() * 1);
	dst.w = currentFrame.w * 1;
	dst.h = currentFrame.h * 1;

	SDL_RenderCopy(_renderer, entity.getTexture(), &src, &dst);
}
