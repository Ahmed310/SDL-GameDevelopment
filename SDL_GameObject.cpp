#include "SDL_GameObject.h"

#include"TextureManager.h"
#include "Game.h"

SDL_GameObject::SDL_GameObject()
	: GameObject(), m_position(0, 0), m_velocity(0, 0), m_accelaration(0,0)
{
	
//	m_width = params->GetWidth();
//	m_height = params->GetHeight();

//	m_textureID = params->GetTextureID();

	m_currentFrame = 1;
	m_currentRow = 1;
}


SDL_GameObject::~SDL_GameObject()
{
	
}


void SDL_GameObject::load(const LoaderParams *pParams)
{
	m_position = Vector2D(pParams->GetX(), pParams->GetY());
	m_velocity = Vector2D(0, 0);
	m_accelaration = Vector2D(0, 0);
	m_width = pParams->GetWidth();
	m_height = pParams->GetHeight();
	m_textureID = pParams->GetTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;
//	m_numFrames = pParams->GetNumFrames();
}

void SDL_GameObject::Draw()
{

	if (m_velocity.GetX() > 0)
	{
		TextureManager::Instance()->DrawFrame(m_textureID,
			m_position.GetX(),
			m_position.GetY(),
			m_width,
			m_height,
			m_currentRow,
			m_currentFrame,
			Game::Instance()->GetRenderer(),
			SDL_FLIP_HORIZONTAL);
	}
	else
	{
		TextureManager::Instance()->DrawFrame(m_textureID,
			m_position.GetX(),
			m_position.GetY(),
			m_width,
			m_height,
			m_currentRow,
			m_currentFrame,
			Game::Instance()->GetRenderer(),
			SDL_FLIP_NONE);
	}
	
}
void SDL_GameObject::Update()
{
	m_velocity += m_accelaration;
	m_position += m_velocity;
}
void SDL_GameObject::Clean()
{}