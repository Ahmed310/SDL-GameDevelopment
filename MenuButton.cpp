#include "MenuButton.h"
#include "InputHandler.h"
MenuButton::MenuButton(const LoaderParams* params)
:SDL_GameObject(params)
{
	m_currentFrame = MOUSE_OUT;
}
void MenuButton::draw()
{
	SDL_GameObject::Draw();
}
void MenuButton::update()
{
	Vector2D* mousePos = InputHandler::Instance()->GetMousePosition();
	if (mousePos->GetX() < (m_position.GetX() + m_width)
		&& mousePos->GetX() > m_position.GetX()
		&& mousePos->GetY() < (m_position.GetY() + m_height)
		&& mousePos->GetY() > m_position.GetY())
	{
		m_currentFrame = MOUSE_OVER;
		if (InputHandler::Instance()->GetMouseButtonState(LEFT))
		{
			m_currentFrame = CLICKED;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}
void MenuButton::clean()
{
	SDL_GameObject::Clean();
}