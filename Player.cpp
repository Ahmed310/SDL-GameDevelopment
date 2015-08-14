#include "Player.h"

#include<string>

Player::Player()
{
}


Player::~Player()
{
}

void Player::Load(int x, int y, int w, int h, std::string textureID)
{
	GameObject::Load(x, y ,w ,h ,textureID);
}
void Player::Draw(SDL_Renderer* renderer)
{
	GameObject::Draw(renderer);
	
}
void Player::Update()
{
	GameObject::Update();
	m_x -= 1;
}
void Player::Clean()
{
	GameObject::Clean();
}