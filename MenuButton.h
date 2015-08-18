#ifndef BUTTON_H
#define BUTTON_H

#include "SDL_GameObject.h"
class MenuButton : public SDL_GameObject
{
public:
	MenuButton(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

enum  button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};
#endif