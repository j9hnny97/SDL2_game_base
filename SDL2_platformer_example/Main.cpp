
#include "Entity.hpp"
#include "Logger.hpp"
#include "MainLoopTickController.hpp"
#include "RenderWindow.hpp"
#include "Utils.hpp"

#include <SDL.h>
#include <SDL_image.h>

int main(int argv, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		Logger::logError("SDL library initialization failed", SDL_GetError());
		Logger::logInfo("Exiting...");
		return 1;
	}

	if (!IMG_Init(IMG_INIT_PNG))
	{
		Logger::logError("SDL_image library initialization failed", SDL_GetError());
		Logger::logInfo("Exiting...");
		return 1;
	}

	SDL_Event event;
	MainLoopTickController tickController;
	RenderWindow window("Game", 1280, 720);

	SDL_Texture* girlTexture = window.loadTexture("res/gfx/girl.png");
	Entity girl0(10, 10, girlTexture);
	Entity girl1(110, 10, girlTexture);
	Entity girl2(210, 10, girlTexture);

	bool gameIsRunning = true;

	while (gameIsRunning)
	{
		tickController.tickStarted();

		while (tickController.tickIsOngoing())
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					gameIsRunning = false;
				}
			}

			window.clear();
			window.render(girl0);
			window.render(girl1);
			window.render(girl2);
			window.display();

			tickController.tickUpdate();
		}

		tickController.tickEnded(window.getRefreshRate());
	}

	window.destroy();
	SDL_Quit();

	Logger::logInfo("Exiting...");
	return 0;
}
