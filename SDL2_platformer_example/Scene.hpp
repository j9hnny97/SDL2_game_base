#ifndef SCENE_HPP
#define SCENE_HPP

#include "Line.hpp"
#include "Texture.hpp"

#include <vector>

class Scene : public Entity
{
public:
	Scene(SDL_Renderer* renderer);

	void render() override;

private:
	std::vector<Texture> initializeBalls();

	std::vector<Texture> _balls;
	Line _line;
	Texture _table;
};

#endif