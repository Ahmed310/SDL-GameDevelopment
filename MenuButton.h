#ifndef BUTTON_H
#define BUTTON_H

#include "SDL_GameObject.h"
#include "GameObjectFactory.h"

class MenuButton : public SDL_GameObject
{
public:
	MenuButton();
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
	virtual void load(const LoaderParams* pParams);

	void SetCallback(void(*callback)()) { m_callback = callback; }
	int GetCallbackID() { return m_callbackID; }

private:
	void(*m_callback)();
	bool m_released;
};

enum  button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};

class MenuButtonCreator : public BaseCreator
{
	GameObject* CreateGameObject() const
	{
		return new MenuButton();
	}
};

#endif