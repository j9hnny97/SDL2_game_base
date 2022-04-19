
#include "Scene.hpp"

#include "../base/Logger.hpp"

Scene::Scene(SDL_Renderer* renderer)
	: Entity(renderer)
	, _balls(initializeBalls())
	, _title(renderer)
	, _line(renderer)
	, _table(renderer, "resources/backgrounds/table.png")
{
	_title.positionX = 0.0f;
	_title.positionY = 0.0f;
	_title.sizeX = 800.0f;
	_title.sizeY = 100.0f;

	_line.positionX = 0.0f;
	_line.positionY = 0.0f;
	_line.sizeX = 800.0f;
	_line.sizeY = 600.0f;

	_table.positionX = 100.0f;
	_table.positionY = 150.0f;
	_table.sizeX = 600.0f;
	_table.sizeY = 300.0f;
}

void Scene::render()
{
	_table.render();

	for (auto& ball : _balls)
	{
		ball.render();
	}

	_title.render();
	_line.render();
}

std::vector<Texture> Scene::initializeBalls()
{
	std::vector<Texture> balls;

	for (int i = 0; i < 10; i++)
	{
		balls.emplace_back(_renderer, "resources/others/balls.png", 15 * i, 0);

		auto& newBall = balls.back();
		newBall.sizeX = 15.0f;
		newBall.sizeY = 15.0f;
		newBall.positionX = 300.0f;
		newBall.positionY = 200.0f + 20.0f * i;
	}

	return balls;
}
