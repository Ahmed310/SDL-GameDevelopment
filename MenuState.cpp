#include "MenuState.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
const std::string MenuState::s_menuID = "MENU";



void MenuState::Update()
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Update();
	}
}
void MenuState::Render()
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Draw();
	}
}
bool MenuState::OnEnter()
{
	if (!TextureManager::Instance()->load("./res/buttons.png",
		"playbutton", Game::Instance()->GetRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("./res/buttons.png",
		"exitbutton", Game::Instance()->GetRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(100, 100,200, 70, "playbutton"));
	GameObject* button2 = new MenuButton(new LoaderParams(100, 175,200, 70, "exitbutton"));
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}
bool MenuState::OnExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->ClearFromTextureMap("playbutton");
	TextureManager::Instance()->ClearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}