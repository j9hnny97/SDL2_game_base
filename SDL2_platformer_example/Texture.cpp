
#include "Texture.hpp"

#include "Logger.hpp"
#include "TextureLoader.hpp"

Texture::Texture(SDL_Renderer* renderer, std::string const& filePath, int sectionX, int sectionY)
	: Texture(renderer, TextureLoader::getTexture(renderer, filePath), sectionX, sectionY)
{
}

Texture::Texture(SDL_Renderer* renderer, SDL_Texture* texture, int sectionX, int sectionY)
	: Entity(renderer)
	, scale(1.0f)
	, _texture(texture)
{
	_currentFrame.x = sectionX;
	_currentFrame.y = sectionY;

	sizeX.addObserver([this](auto const& value) { _currentFrame.w = value; });
	sizeY.addObserver([this](auto const& value) { _currentFrame.h = value; });
}

void Texture::render()
{
	if (visible.getValue())
	{
		SDL_Rect src;
		src.x = _currentFrame.x;
		src.y = _currentFrame.y;
		src.w = _currentFrame.w;
		src.h = _currentFrame.h;

		SDL_Rect dst;
		dst.x = static_cast<int>(positionX.getValue() * scale.getValue());
		dst.y = static_cast<int>(positionY.getValue() * scale.getValue());
		dst.w = static_cast<int>(_currentFrame.w * scale.getValue());
		dst.h = static_cast<int>(_currentFrame.h * scale.getValue());

		SDL_RenderCopy(_renderer, _texture, &src, &dst);
	}
}
