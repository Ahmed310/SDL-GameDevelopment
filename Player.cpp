#include "Player.h"
#include "InputHandler.h"

#include"SDL2/SDL.h"

Player::Player(const LoaderParams* params)
:SDL_GameObject(params)
{}

Player::~Player()
{
}

void Player::HandleInput()
{
	/*if (InputHandler::Instance()->GetMouseButtonState(LEFT))
	{
		m_velocity.SetX(1);
	}
	else
	{
		m_velocity.SetX(0);
	}*/

//	Vector2D* pos = InputHandler::Instance()->GetMousePosition();
//	m_velocity = (*pos - m_position) / 100;


	/*if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.SetX(-2);
	}
	else if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.SetX(2);
	}

	if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.SetY(-2);
	}
	else if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.SetY(2);
	}*/

	Vector2D* target = InputHandler::Instance()->GetMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
}

void Player::Draw()
{
	SDL_GameObject::Draw();
	
}
void Player::Update()
{
	HandleInput();
//	m_accelaration.SetX(1);
//	m_velocity.SetX(1);	
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));

	SDL_GameObject::Update();
}
void Player::Clean()
{
	SDL_GameObject::Clean();
}