#include "TextureManager.h"

#include"SDL2/SDL_image.h"

TextureManager* TextureManager::s_instance = 0;

TextureManager* TextureManager::Instance()
{
	if (s_instance == 0)
	{
		s_instance = new TextureManager();
		return s_instance;
	}
	return s_instance;
}

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{

}
void TextureManager::ClearFromTextureMap(std::string id)
{
	m_textureMap.erase(id);
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* renderer)
{
	SDL_Surface* tmpSurface = IMG_Load(fileName.c_str());
	if (tmpSurface == 0)	return false;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	if (texture != 0)
	{
		m_textureMap[id] = texture;
		return true;
	}

	return false;
}

void TextureManager::Draw(std::string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;

	srcRect.x = srcRect.y = 0;
	srcRect.w = dstRect.w = w;
	srcRect.h = dstRect.h = h;
	dstRect.x = x;
	dstRect.y = y;

	SDL_RenderCopyEx(renderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);

}
void TextureManager::DrawFrame(std::string id, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	srcRect.x = w * currentFrame;
	srcRect.y = h * (currentRow - 1);
	srcRect.w = dstRect.w = w;
	srcRect.h = dstRect.h = h;
	dstRect.x = x;
	dstRect.y = y;

	SDL_RenderCopyEx(renderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}