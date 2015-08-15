#include "Player.h"


#include"SDL2/SDL.h"

Player::Player(const LoaderParams* params)
:SDL_GameObject(params)
{}

Player::~Player()
{
}


void Player::Draw()
{
	SDL_GameObject::Draw();
	
}
void Player::Update()
{
	m_position.SetX(m_position.GetX() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
}
void Player::Clean()
{
	SDL_GameObject::Clean();
}