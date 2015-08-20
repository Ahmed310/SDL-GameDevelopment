#include "Game.h"
#include "InputHandler.h"


InputHandler* InputHandler::s_instance = 0 ;

InputHandler* InputHandler::Instance()
{
	if (s_instance == 0)
	{
		s_instance = new InputHandler();
	}
	return s_instance;
}

InputHandler::InputHandler()
{
	for (size_t i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}

	m_mousePosition = new Vector2D(0, 0);
}


InputHandler::~InputHandler()
{
}

void InputHandler::Reset()
{
    m_mouseButtonStates[LEFT] = false;
	m_mouseButtonStates[MIDDLE] = false;
	m_mouseButtonStates[RIGHT] = false;
}

bool InputHandler::GetMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::GetMousePosition()
{
	return m_mousePosition;
}


bool InputHandler::IsKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0)
	{
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}


void InputHandler::Update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		m_keystates = SDL_GetKeyboardState(0);
		
		if (event.type == SDL_QUIT)
		{
			Game::Instance()->quit();
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = true;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = true;
			}
		}
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = false;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = false;
			}
		}
		if (event.type == SDL_MOUSEMOTION)
		{
			m_mousePosition->SetX((float)event.motion.x);
			m_mousePosition->SetY((float)event.motion.y);
		}

	}

}

void InputHandler::Clean()
{}
