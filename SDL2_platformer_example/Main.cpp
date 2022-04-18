
#include "base/Logger.hpp"
#include "entities/Entity.hpp"
#include "window/Mouse.hpp"
#include "window/Scene.hpp"
#include "window/WindowRenderer.hpp"
#include "window/WindowSyncer.hpp"

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
	WindowRenderer windowRenderer("Game", 800, 600);
	WindowSyncer windowSyncer;

	Mouse mouse(windowRenderer.getRenderer());
	Scene scene(windowRenderer.getRenderer());

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

				mouse.processEvent(event);

				//else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP)
				//{
				//	EZ_LOG(Logger::Level::Info, event.key.keysym.sym);
				//}
				//else if (event.type == SDL_MOUSEMOTION)
				//{
				//	EZ_LOG(Logger::Level::Info, "Mouse is moving [" << event.button.x << ", " << event.button.y << "]");
				//	SDL_ShowCursor(SDL_DISABLE);
				//}
				//else if (event.type == SDL_MOUSEBUTTONDOWN)
				//{
				//	switch (event.button.button)
				//	{
				//	case SDL_BUTTON_LEFT:
				//		//Logger::logInfo("left click! [" << static_cast<int>(event.button.x) << ", " << static_cast<int>(event.button.y) << "]");
				//		break;
				//	case SDL_BUTTON_RIGHT:
				//		//Logger::logInfo("right click! [" << static_cast<int>(event.button.x) << ", " << static_cast<int>(event.button.y) << "]");
				//		break;
				//	default:
				//		break;
				//	}
				//	break;
				//}
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
