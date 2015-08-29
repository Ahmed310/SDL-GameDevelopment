#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "MenuState.h"
#include "GameObject.h"

class MainMenuState : public MenuState
{
public:
	virtual void Update();
	virtual void Render();
	virtual bool OnEnter();
	virtual bool OnExit();
	virtual std::string GetStateID() const { return s_menuID; }
private:
	virtual void SetCallbacks(const std::vector<Callback>& callbacks);
	// call back functions for menu items
	static void MenuToPlay();
	static void ExitFromMenu();
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
};

#endif