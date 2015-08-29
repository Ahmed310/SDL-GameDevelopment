#include "Enemy.h"

#include"SDL2/SDL.h"
Enemy::Enemy()
:SDL_GameObject()
{
	m_velocity.SetY(2);
	m_velocity.SetX(0.001f);

}


Enemy::~Enemy()
{
}

void Enemy::Draw()
{
	SDL_GameObject::Draw();
}
void Enemy::Update()
{

	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));

	if (m_position.GetY() < 0)
	{
		m_velocity.SetY(2);
	}
	else if (m_position.GetY() > 450)
	{
		m_velocity.SetY(-2);
	}

	SDL_GameObject::Update();
}
void Enemy::Clean()
{}