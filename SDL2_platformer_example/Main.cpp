
#include "base/InputCentral.hpp"
#include "base/Logger.hpp"
#include "base/Mouse.hpp"
#include "entities/Entity.hpp"
#include "window/Scene.hpp"
#include "window/WindowRenderer.hpp"
#include "window/WindowSyncer.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int main(int argv, char* args[])
{
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

	if (TTF_Init() == -1)
	{
		EZ_LOG(Logger::Level::Error, "SDL_ttf library initialization failed (" << SDL_GetError() << ")");
		return 1;
	}

	InputCentral _inputCentral;
	WindowRenderer windowRenderer("Game", 800, 600);
	WindowSyncer windowSyncer;

	Mouse mouse(windowRenderer.getRenderer());
	Scene scene(windowRenderer.getRenderer());

	bool gameIsRunning = true;

	{
		Scene potato(windowRenderer.getRenderer());
	}

	while (gameIsRunning)
	{
		windowSyncer.tickStarted();

		while (windowSyncer.tickIsOngoing())
		{
			while (_inputCentral.pollEvent())
			{
				if (_inputCentral.getCurrentInput().type == InputCentral::Input::Quit)
				{
					gameIsRunning = false;
				}
			}

			windowRenderer.clear();
			scene.render();

			mouse.render();

			windowRenderer.display();
			windowSyncer.tickUpdate();
		}

		windowSyncer.tickEnded(windowRenderer.getRefreshRate());
	}

	windowRenderer.destroy();
	SDL_Quit();

	return 0;
}
