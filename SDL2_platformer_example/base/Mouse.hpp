#ifndef MOUSE_HPP
#define MOUSE_HPP

#include "../entities/Texture.hpp"

class Mouse : public Entity
{
public:
	Mouse(SDL_Renderer* renderer);

	void processEvent(SDL_Event const& event);
	void render() override;

private:

	Texture _clickedTexture;
	Texture _defaultTexture;
};

#endif