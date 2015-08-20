#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Vector2D.h"
#include <vector>
#include "SDL2/SDL.h"
class InputHandler
{
public:
	
	static InputHandler* Instance();
	
	void Update();
	void Clean();
	bool GetMouseButtonState(int buttonNumber);
	Vector2D* GetMousePosition();

	bool IsKeyDown(SDL_Scancode key);
	void Reset();

private:
	InputHandler();
	~InputHandler();

	static InputHandler* s_instance;

	
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;

	const Uint8* m_keystates;



};

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};
#endif
