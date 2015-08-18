#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameState.h"
#include "GameObject.h"
#include <vector>
class MenuState : public GameState
{
public:
	

	virtual void Update();
	virtual void Render();
	virtual bool OnEnter();
	virtual bool OnExit();

	virtual std::string GetStateID() const { return s_menuID; }

private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
};

#endif