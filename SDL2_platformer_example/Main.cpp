
#include "Entity.hpp"
#include "Logger.hpp"
#include "Scene.hpp"
#include "Utils.hpp"
#include "WindowRenderer.hpp"
#include "WindowSyncer.hpp"

#include <SDL.h>
#include <SDL_image.h>

int main(int argv, char* args[])
{
	EZ_LOG(Logger::Level::Error, "This is an error.");
	EZ_LOG(Logger::Level::Info, "This is an info.");
	EZ_LOG(Logger::Level::Warning, "This is a warning.");

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		EZ_LOG(Logger::Level::Error, "SDL library initialization failed (" << SDL_GetError() << ")");
		return 1;
	}

	if (!IMG_Init(IMG_INIT_PNG))
	{
		EZ_LOG(Logger::Level::Error, "SDL_image library initialization failed (" << SDL_GetError() << ")");
		return 1;
	}

	SDL_Event event;
	WindowRenderer windowRenderer("Game", 1280, 720);
	WindowSyncer windowSyncer;

	Scene scene(windowRenderer);

	bool gameIsRunning = true;

	while (gameIsRunning)
	{
		windowSyncer.tickStarted();

		while (windowSyncer.tickIsOngoing())
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					gameIsRunning = false;
				}
				else if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					switch (event.button.button)
					{
					case SDL_BUTTON_LEFT:
						//Logger::logInfo("left click! [" << static_cast<int>(event.button.x) << ", " << static_cast<int>(event.button.y) << "]");
						break;
					case SDL_BUTTON_RIGHT:
						//Logger::logInfo("right click! [" << static_cast<int>(event.button.x) << ", " << static_cast<int>(event.button.y) << "]");
						break;
					default:
						break;
					}
					break;
				}
			}

			windowRenderer.clear();
			scene.renderEntities();
			windowRenderer.display();

			windowSyncer.tickUpdate();
		}

		windowSyncer.tickEnded(windowRenderer.getRefreshRate());
	}

	windowRenderer.destroy();
	SDL_Quit();

	return 0;
}
