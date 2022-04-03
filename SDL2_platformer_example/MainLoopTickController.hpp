#ifndef MAIN_LOOP_TICK_CONTROLLER_HPP
#define MAIN_LOOP_TICK_CONTROLLER_HPP

class MainLoopTickController
{
public:
	MainLoopTickController();

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