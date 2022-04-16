#ifndef TEXTURE_LOADER_HPP
#define TEXTURE_LOADER_HPP

#include "Logger.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class TextureLoader
{
public:
	static SDL_Texture* getTexture(SDL_Renderer* renderer, std::string const& filePath)
	{
		SDL_Texture* texture = IMG_LoadTexture(renderer, filePath.c_str());

		if (texture == nullptr)
		{
			EZ_LOG(Logger::Level::Error, "Failed to load texture " << filePath << " (" << SDL_GetError() << ")");
		}

		return texture;
	}
};

#endif