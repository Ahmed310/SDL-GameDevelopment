#include "GameOverState.h"

#include "GameObject.h"
#include"TextureManager.h"
#include"Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"

#include <iostream>

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::GameOverToMain()
{
//	Game::Instance()->GetStateMachine()->ChangeState(new MenuState());
}
void GameOverState::RestartPlay()
{
	Game::Instance()->GetStateMachine()->ChangeState(new PlayState());
}
bool GameOverState::OnExit()
{
	return false;
}
bool GameOverState::OnEnter()
{
	if (!TextureManager::Instance()->load("./res/gameover.png","gameovertext", Game::Instance()->GetRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("./res/menu.png","mainbutton", Game::Instance()->GetRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("./res/restart.png","restartbutton", Game::Instance()->GetRenderer()))
	{
		return false;
	}

//	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 200, 100, "gameovertext"), 2,2);
//	GameObject* button1 = new MenuButton(new LoaderParams(200, 200,200, 75, "mainbutton"), GameOverToMain);
//	GameObject* button2 = new MenuButton(new LoaderParams(200, 300,200, 75, "restartbutton"), RestartPlay);

//	m_gameObjects.push_back(gameOverText);
//	m_gameObjects.push_back(button1);
//	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}


void GameOverState::Update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Update();
	}
}
void GameOverState::Render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Draw();
	}
}