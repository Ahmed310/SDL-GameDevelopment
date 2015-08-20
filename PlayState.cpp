#include "PlayState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "PauseState.h"
#include "InputHandler.h"
#include"GameOverState.h"
#include "SDL_GameObject.h"

#include <iostream>
const std::string PlayState::s_playID = "PLAY";




void PlayState::Update()
{
	if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->GetStateMachine()->PushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Update();
	}

	if (CheckCollision(dynamic_cast<SDL_GameObject*>(m_gameObjects[0]), dynamic_cast<SDL_GameObject*>(m_gameObjects[1])))
	{
		Game::Instance()->GetStateMachine()->PushState(new GameOverState());
	}
}
void PlayState::Render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Draw();
	}
}
bool PlayState::OnEnter()
{
	
	if (!TextureManager::Instance()->load("./res/helicopter.png", "helicopter", Game::Instance()->GetRenderer()))
	{
		return false;
	}

	GameObject* player = new Player(new LoaderParams(500, 100, 115, 65, "helicopter"));
	GameObject* enemy = new Enemy(new LoaderParams(100, 100, 115, 65, "helicopter"));
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);

	std::cout << "PlayState Enters ! \n";
	return true;
}
bool PlayState::OnExit()
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->ClearFromTextureMap("helicopter");

	std::cout << "PlayState Exit ! \n";
	return true;
}


bool PlayState::CheckCollision(SDL_GameObject* p1, SDL_GameObject*
	p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	
	leftA = p1->GetPosition().GetX();
	rightA = p1->GetPosition().GetX() + p1->GetWidth();
	topA = p1->GetPosition().GetY();
	bottomA = p1->GetPosition().GetY() + p1->GetHeight();
	//Calculate the sides of rect B
	leftB = p2->GetPosition().GetX();
	rightB = p2->GetPosition().GetX() + p2->GetWidth();
	topB = p2->GetPosition().GetY();
	bottomB = p2->GetPosition().GetY() + p2->GetHeight();
	//If any of the sides from A are outside of B
	if (bottomA <= topB){ return false; }
	if (topA >= bottomB){ return false; }
	if (rightA <= leftB){ return false; }
	if (leftA >= rightB){ return false; }
	return true;
}