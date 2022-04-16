#ifndef LINE_HPP
#define LINE_HPP

#include "Entity.hpp"

class Line : public Entity
{
public:
	Line(SDL_Renderer* renderer);

	void render() override;
};

#endif