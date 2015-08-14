#include "SDL_GameObject.h"

#include"TextureManager.h"
#include "Game.h"

SDL_GameObject::SDL_GameObject(const LoaderParams* params)
	: GameObject(params)
{
	m_x = params->GetX();
	m_y = params->GetY();

	m_width = params->GetWidth();
	m_height = params->GetHeight();

	m_textureID = params->GetTextureID();

	m_currentFrame = 1;
	m_currentRow = 1;
}


SDL_GameObject::~SDL_GameObject()
{
	
}


void SDL_GameObject::Draw()
{
	TextureManager::Instance()->DrawFrame( m_textureID, 
										   m_x, 
										   m_y, 
										   m_width, 
										   m_height, 
										   m_currentRow, 
										   m_currentFrame, 
										   Game::Instance()->GetRenderer(), 
										   SDL_FLIP_NONE);
}
void SDL_GameObject::Update()
{}
void SDL_GameObject::Clean()
{}