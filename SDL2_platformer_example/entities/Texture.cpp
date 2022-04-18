
#include "Texture.hpp"

#include "../base/TextureLoader.hpp"

Texture::Texture(SDL_Renderer* renderer, std::string const& filePath, int sectionX, int sectionY)
	: Texture(renderer, TextureLoader::getTexture(renderer, filePath), sectionX, sectionY)
{
}

Texture::Texture(SDL_Renderer* renderer, SDL_Texture* texture, int sectionX, int sectionY)
	: Entity(renderer)
	, scale(1.0f)
	, _texture(texture)
{
	_src.x = sectionX;
	_src.y = sectionY;

	sizeX.addObserver([this](auto const& value) { _src.w = value; });
	sizeY.addObserver([this](auto const& value) { _src.h = value; });
}

void Texture::render()
{
	if (visible.getValue())
	{
		SDL_Rect dst;
		dst.x = static_cast<int>(positionX.getValue() * scale.getValue());
		dst.y = static_cast<int>(positionY.getValue() * scale.getValue());
		dst.w = static_cast<int>(_src.w * scale.getValue());
		dst.h = static_cast<int>(_src.h * scale.getValue());

		SDL_RenderCopy(_renderer, _texture, &_src, &dst);
	}
}
