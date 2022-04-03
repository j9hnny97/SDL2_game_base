#ifndef UTILS_HPP
#define UTILS_HPP

#include <SDL.h>

namespace utils
{
	inline float getTimeInSeconds()
	{
		return static_cast<float>(0.001 * SDL_GetTicks());
	}
}

#endif