#ifndef WINDOW_RENDERER_HPP
#define WINDOW_RENDERER_HPP

#include "Entity.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class WindowRenderer
{
public:
	WindowRenderer(const char* title, int width, int height);

	void clear();
	void destroy();
	void display();
	int getRefreshRate();
	SDL_Texture* loadTexture(std::string const& filePath);
	void render(Entity& entity);

private:
	SDL_Renderer* _renderer;
	SDL_Window* _window;
};

#endif
