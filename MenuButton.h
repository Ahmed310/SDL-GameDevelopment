#ifndef BUTTON_H
#define BUTTON_H

#include "SDL_GameObject.h"
class MenuButton : public SDL_GameObject
{
public:
	MenuButton(const LoaderParams* pParams, void(*callback)());
	virtual void Draw();
	virtual void Update();
	virtual void Clean();

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
#endif