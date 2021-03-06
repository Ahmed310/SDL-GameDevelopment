#include "MenuButton.h"
#include "InputHandler.h"

#include <iostream>
MenuButton::MenuButton()
	:SDL_GameObject()
{
	m_currentFrame = MOUSE_OUT;
	
}

void MenuButton::load(const LoaderParams *pParams)
{
	SDL_GameObject::load(pParams);
	m_callbackID = pParams->GetCallBackID();
	m_currentFrame = MOUSE_OUT;
}

void MenuButton::Draw()
{
	SDL_GameObject::Draw();
}
void MenuButton::Update()
{
	Vector2D* mousePos = InputHandler::Instance()->GetMousePosition();
	if (mousePos->GetX() < (m_position.GetX() + m_width)
		&& mousePos->GetX() > m_position.GetX()
		&& mousePos->GetY() < (m_position.GetY() + m_height)
		&& mousePos->GetY() > m_position.GetY())
	{
		m_currentFrame = MOUSE_OVER;
		if (InputHandler::Instance()->GetMouseButtonState(LEFT) && m_released)
		{
			m_currentFrame = CLICKED;
			m_callback();
			m_released = false;
		}
		else if (!InputHandler::Instance()->GetMouseButtonState(LEFT))
		{
			m_currentFrame = MOUSE_OUT;
			m_released = true;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}

}
void MenuButton::Clean()
{
	SDL_GameObject::Clean();
}