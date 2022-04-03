
#include "MainLoopTickController.hpp"

#include "Utils.hpp"

MainLoopTickController::MainLoopTickController()
	: _accumulator(0.0f)
	, _currentTime(utils::getTimeInSeconds())
	, _ticksOnBegin(0)
	, _timeStep(0.01f)
{
}

void MainLoopTickController::tickEnded(int refreshRate)
{
	int frameTicks = SDL_GetTicks() - _ticksOnBegin;

	if (frameTicks < 1000 / refreshRate)
	{
		SDL_Delay(1000 / refreshRate - frameTicks);
	}
}

bool MainLoopTickController::tickIsOngoing()
{
	return _accumulator >= _timeStep;
}

void MainLoopTickController::tickStarted()
{
	_ticksOnBegin = SDL_GetTicks();

	float newTime = utils::getTimeInSeconds();
	float frameTime = newTime - _currentTime;

	_currentTime = newTime;
	_accumulator += frameTime;
}

void MainLoopTickController::tickUpdate()
{
	_accumulator -= _timeStep;
}
