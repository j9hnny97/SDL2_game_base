#ifndef WINDOW_SYNCER_HPP
#define WINDOW_SYNCER_HPP

class WindowSyncer
{
public:
	WindowSyncer();

	void tickEnded(int refreshRate);
	bool tickIsOngoing();
	void tickStarted();
	void tickUpdate();

private:
	float _accumulator;
	float _currentTime;
	int _ticksOnBegin;

	float const _timeStep;
};

#endif