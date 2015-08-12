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

//	SDL_Surface* tmpSurface = SDL_LoadBMP("./res/animation.bmp");

	SDL_Surface* tmpSurface = IMG_Load("./res/animation.png");

	m_texture = SDL_CreateTextureFromSurface(m_renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	//SDL_QueryTexture(m_texture, NULL, NULL, &m_sourceRect.w, &m_sourceRect.h);
	m_sourceRect.w = 62;;
	m_sourceRect.h = 82;

	m_destRect.x = 0;
	m_destRect.y = 0;
	m_destRect.w = m_sourceRect.w;
	m_destRect.h = m_sourceRect.h;
}
void Game::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 75, 127, 1);
	SDL_RenderClear(m_renderer);

//	SDL_RenderCopy(m_renderer, m_texture, &m_sourceRect, &m_destRect);

	SDL_RenderCopyEx(m_renderer, m_texture, &m_sourceRect, &m_destRect, 0, 0, SDL_FLIP_HORIZONTAL);
	SDL_RenderPresent(m_renderer);

}
void Game::update()
{
	m_sourceRect.x = 62 * int(((SDL_GetTicks() / 100) % 5));
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