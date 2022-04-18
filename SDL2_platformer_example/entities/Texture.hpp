#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "Entity.hpp"

#include <string>

class Texture : public Entity
{
public:
	Texture(SDL_Renderer* renderer, std::string const& filePath, int sectionX = 0, int sectionY = 0);
	Texture(SDL_Renderer* renderer, SDL_Texture* texture, int sectionX = 0, int sectionY = 0);

	Field<float> scale;

	void render() override;

private:

	SDL_Rect _src;
	SDL_Texture* _texture;
};

#endif