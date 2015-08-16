#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include"InputHandler.h"


#include <iostream>

Game* Game::s_instance = 0;

Game* Game::Instance()
{
	if (s_instance == 0)
	{
		s_instance = new Game();
		return s_instance;
	}
	return s_instance;
}


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

	TextureManager::Instance()->load("./res/animation.png", "animate", m_renderer);


	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 62, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(10, 10, 62, 82, "animate")));
}
void Game::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 75, 127, 1);
	SDL_RenderClear(m_renderer);

//	TextureManager::Instance()->Draw("animate", 10, 10, 62,82, GetRenderer(), SDL_FLIP_NONE);

//	TextureManager::Instance()->DrawFrame("animate", 100, 100, 62, 82,1,1, GetRenderer(), SDL_FLIP_NONE);
	
	for (std::vector<GameObject*>::size_type i = 0 ; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Draw();
	}

	SDL_RenderPresent(m_renderer);

}
void Game::update()
{
	
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Update();
	}
}


void Game::handleEvents()
{
	/*SDL_Event event;
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
	}*/

	InputHandler::Instance()->Update();

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
		m_frameStart = SDL_GetTicks();

		handleEvents();
		update();
		render();

		m_frameTime = SDL_GetTicks() - m_frameStart;

		if (m_frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - m_frameTime));
		}

		
	}
	clean();
}