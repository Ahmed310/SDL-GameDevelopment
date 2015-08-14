#include "GameObject.h"
#include "TextureManager.h"

#include <string>

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Load(int x, int y, int w, int h, std::string textureID)
{
	m_x = x;
	m_y = y;

	m_width = w;
	m_height = h;

	m_textureID = textureID;
	m_currentFrame = 1;
	m_currentRow = 1;
}

void GameObject::Draw(SDL_Renderer* renderer)
{
	TextureManager::Instance()->DrawFrame(  m_textureID, 
											m_x, 
											m_y, 
											m_width, 
											m_height, 
											m_currentRow, 
											m_currentFrame, 
											renderer, 
											SDL_FLIP_NONE);
	
}

void GameObject::Update()
{
	m_x += 1;
}
void GameObject::Clean()
{
}