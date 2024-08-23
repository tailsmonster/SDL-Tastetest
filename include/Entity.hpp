#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
	Entity(vector2f p_position, SDL_Texture* p_texture);
	Vector2f position;
	SDL_Texture* texture;

	Vector2f& getPosition();

	SDL_Texture* getTexture();

	SDL_Rect getCurrFrame();

	// void setX(float new_x);
	// void setY(float new_y);
	// void setTexture(SDL_Texture* new_texture);
private:
	Vector2f position;
	SDL_Rect currFrame;
	SDL_Texture* texture;
};