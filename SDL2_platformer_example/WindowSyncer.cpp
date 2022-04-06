
#include "WindowSyncer.hpp"

#include "Utils.hpp"

WindowSyncer::WindowSyncer()
	: _accumulator(0.0f)
	, _currentTime(utils::getTimeInSeconds())
	, _ticksOnBegin(0)
	, _timeStep(0.01f)
{
}

void WindowSyncer::tickEnded(int refreshRate)
{
	int frameTicks = SDL_GetTicks() - _ticksOnBegin;

	if (frameTicks < 1000 / refreshRate)
	{
		SDL_Delay(1000 / refreshRate - frameTicks);
	}
}

bool WindowSyncer::tickIsOngoing()
{
	return _accumulator >= _timeStep;
}

void WindowSyncer::tickStarted()
{
	_ticksOnBegin = SDL_GetTicks();

	float newTime = utils::getTimeInSeconds();
	float frameTime = newTime - _currentTime;

	_currentTime = newTime;
	_accumulator += frameTime;
}

void WindowSyncer::tickUpdate()
{
	_accumulator -= _timeStep;
}
