#include "Game.h"

#include <iostream>

Game::Game()
{
}


Game::~Game()
{
}

void Game::init(const char* title, int x, int y, int w, int h, Uint32 flag)
{
	m_running = true;

	if ( SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, flag);

		if (m_window != NULL)
			m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	}
	else
	{
		std::cout << "SDL Failed to Init";
	}
}
void Game::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 76, 127, 1);
	SDL_RenderClear(m_renderer);

	SDL_RenderPresent(m_renderer);

}
void Game::update()
{
}


void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_running = false;
			break;
		default:
			break;
		}
	}
}
void Game::clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}



void Game::run()
{
	while (m_running)
	{
		handleEvents();
		update();
		render();
	}
	clean();
}