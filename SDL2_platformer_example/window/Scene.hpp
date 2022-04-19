#ifndef SCENE_HPP
#define SCENE_HPP

#include "../entities/Label.hpp"
#include "../entities/Line.hpp"
#include "../entities/Texture.hpp"

#include <vector>

class Scene : public Entity
{
public:
	Scene(SDL_Renderer* renderer);

	void render() override;

private:
	std::vector<Texture> initializeBalls();

	std::vector<Texture> _balls;
	Label _title;
	Line _line;
	Texture _table;
};

#endif