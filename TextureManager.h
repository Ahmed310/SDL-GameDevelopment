#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H


#include"SDL2/SDL.h"
#include<map>
#include <string>

class TextureManager
{
public:
	
	~TextureManager();

	static TextureManager* Instance();
	

public:
	bool load(std::string fileName, std::string id, SDL_Renderer* renderer);
	void ClearFromTextureMap(std::string id);
	void Draw(	std::string id, 
				int x, 
				int y, 
				int w, 
				int h, 
				SDL_Renderer* renderer, 
				SDL_RendererFlip flip );

	void DrawFrame( std::string id, 
					int x, 
					int y, 
					int w, 
					int h, 
					int currentRow, 
					int currentFrame, 
					SDL_Renderer* renderer, 
					SDL_RendererFlip flip );

private:
	TextureManager();
private:
	static TextureManager* s_instance;
	std::map<std::string, SDL_Texture*> m_textureMap;

};


#endif
