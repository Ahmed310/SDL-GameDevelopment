#include<iostream>
#include "SDL2/SDL.h"
#include"Game.h"


const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

int main()
{

	Game* game = new Game();

	game->init("SDL2 Game Dev", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	game->run();

	return 0;
}