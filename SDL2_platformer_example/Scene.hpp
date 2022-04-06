#ifndef SCENE_HPP
#define SCENE_HPP

#include "Entity.hpp"
#include "WindowRenderer.hpp"

#include <vector>

class Scene
{
public:
	Scene(WindowRenderer& renderWindow);

	void renderEntities();

private:
	std::vector<Entity> _entities;

	WindowRenderer& _windowRenderer;
};

#endif