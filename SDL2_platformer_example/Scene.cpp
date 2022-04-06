
#include "Scene.hpp"

Scene::Scene(WindowRenderer& windowRenderer)
	: _windowRenderer(windowRenderer)
{
	SDL_Texture* girlTexture = _windowRenderer.loadTexture("res/gfx/girl.png");

	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			_entities.emplace_back(100.0f * row, 150.0f * column, girlTexture);
		}
	}
}

void Scene::renderEntities()
{
	for (auto& entity : _entities)
	{
		_windowRenderer.render(entity);
	}
}
