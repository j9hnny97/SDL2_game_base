#ifndef RENDER_WINDOW_HPP
#define RENDER_WINDOW_HPP

#include "Entity.hpp"

#include <SDL.h>
#include <SDL_image.h>

class RenderWindow
{
public:
	RenderWindow(const char* title, int width, int height);

	void clear();
	void destroy();
	void display();
	int getRefreshRate();
	SDL_Texture* loadTexture(const char* filePath);
	void render(Entity& entity);

private:
	SDL_Renderer* _renderer;
	SDL_Window* _window;
};

#endif
