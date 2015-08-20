#include "PauseState.h"
#include "Game.h"
#include"MenuState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "InputHandler.h"

#include <iostream>
const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::PauseToMain()
{
	Game::Instance()->GetStateMachine()->ChangeState(new MenuState());
}
void PauseState::ResumeToPlay()
{
	Game::Instance()->GetStateMachine()->PopState();
}
void PauseState::Update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Update();
	}
}
void PauseState::Render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Draw();
	}
}
bool PauseState::OnEnter()
{
	if (!TextureManager::Instance()->load("./res/resume.png","resumebutton", Game::Instance()->GetRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("./res/menu.png","mainbutton", Game::Instance()->GetRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(200, 100,200, 80, "mainbutton"), PauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300,200, 80, "resumebutton"), ResumeToPlay);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}
bool PauseState::OnExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->ClearFromTextureMap("resumebutton");
	TextureManager::Instance()->ClearFromTextureMap("mainbutton");
	// reset the mouse button states to false
	InputHandler::Instance()->Reset();
	std::cout << "exiting PauseState\n";
	return true;
}