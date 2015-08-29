#include "MainMenuState.h"
#include "MenuButton.h"
#include "StateParser.h"
#include "TextureManager.h"

const std::string MainMenuState::s_menuID = "MENU";

bool MainMenuState::OnEnter()
{
	// parse the state
	StateParser stateParser;
	stateParser.ParseState("./res/states.txt", s_menuID, &m_gameObjects,&m_textureIDList);
	m_callbacks.push_back(0); //pushback 0 callbackID start from 1
	m_callbacks.push_back(MenuToPlay);
	m_callbacks.push_back(ExitFromMenu);
	// set the callbacks for menu items
	SetCallbacks(m_callbacks);
	std::cout << "entering MenuState\n";
	return true;
}

bool MainMenuState::OnExit()
{
	// clear the texture manager
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->ClearFromTextureMap(m_textureIDList[i]);
	}
	return true;
}

void MainMenuState::SetCallbacks(const std::vector<Callback>& callbacks)
{
	// go through the game objects
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		// if they are of type MenuButton then assign a callback based on the id passed in from the file
			if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
			{
				MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
				pButton->SetCallback(callbacks[pButton->GetCallbackID()]);
			}
	}
}

void MainMenuState::Update()
{
	MenuState::Update();
}
void MainMenuState::Render()
{
	MenuState::Render();
}


void MainMenuState::MenuToPlay(){}
void MainMenuState::ExitFromMenu(){}