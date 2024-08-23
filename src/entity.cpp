#include <SDL2/SDL.h>
#include <SDL2/SDL.h>

#include "Entity.hpp"

Entity::Entity(Vector2f p_position, SDL_Texture* p_texture)
:position(p_position), texture(p_texture)
{
	currFrame.x = 0;
	currFrame.y = 0;
	currFrame.w = 64;
	currFrame.h = 64;
};

// getters
Vector2f& Entity::getPosition()
:pos()
{
	return position;
}	

SDL_Texture* Entity::getTexture()
{
	return texture;
}
SDL_Rect Entity::getCurrFrame()
{
	return currFrame;
}

