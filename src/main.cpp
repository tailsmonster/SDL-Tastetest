#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char* args[]) 
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_INIT has failed. SDL_ERROR: " << SDL_GetError() << std::endl;	
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init has failed. ERROR: " << SDL_GetError() << std::endl;

	RenderWindow window("Project v1.0", 424, 240); // renders our window

	//Game Loop
	bool gameRunning = true;
	SDL_Event event;

	// textures wahoo!!!
	SDL_Texture* main_snoFloTex = window.loadTexture("res/gfx/tiles/main_floor_top_snow.png");
	// Entity dcz_topSnow(100, 50, main_snoFloTex);

	SDL_Texture* main_graFloTex = window.loadTexture("res/gfx/tiles/main_floor_top.png");
	// Entity dcz_top(100, 50, main_graFloTex);

	SDL_Texture* main_dirTex = window.loadTexture("res/gfx/tiles/main_floor_mid.png");
	// Entity dcz_middle(100, 50, main_dirTex);


	//Better than literally placing everything by hand lol.
	std::vector<Entity> dcz_topSnowRow = 
	{
		Entity(Vector2f(0,0),main_snoFloTex),
		Entity(Vector2f(64,0),main_graFloTex),
		Entity(Vector2f(128,64),main_dirTex),
		Entity(Vector2f(128,128),main_dirTex),
	};
	
	//the main loop thats basically our entire project;
	while (gameRunning)
	{
		while(SDL_PollEvent(&event)) 
		{ // THIS IS FOR MAKING SURE THE PROJECT KEEPS RUNNING WHILE OPEN
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
		}
		window.clear();
		// window.render(dcz_middle);
		for (Entity& e : dcz_topSnowRow)
		{
			window.render(e);
		}
		window.display();
	}

	//CleanUp
	window.cleanUp();
	SDL_Quit();
	return 0;
}