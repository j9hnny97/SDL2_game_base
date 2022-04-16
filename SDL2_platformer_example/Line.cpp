
#include "Line.hpp"

#include "Logger.hpp"

Line::Line(SDL_Renderer* renderer)
	: Entity(renderer)
{
}

void Line::render()
{
	auto x1 = positionX.getValue<int>();
	auto y1 = positionY.getValue<int>();

	auto x2 = x1 + sizeX.getValue<int>();
	auto y2 = y1 + sizeY.getValue<int>();

	SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}
