#include "Enemy.h"

#include"SDL2/SDL.h"
Enemy::Enemy(const LoaderParams* params)
:SDL_GameObject(params)
{
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
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
}
void Enemy::Clean()
{}