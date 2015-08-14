#ifndef _Game_H
#define _GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#undef main
class Game
{
public:
	Game();
	~Game();


public:
	void init(const char* title, int x, int y, int w, int h, Uint32 flag);
	void run();

private:
	void render();
	void update();
	void handleEvents();
	void clean();

private:
	bool m_running;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer ;

//	SDL_Texture* m_texture;
//	SDL_Rect m_sourceRect;
//	SDL_Rect m_destRect;

	int m_currrentFrame;
	//TextureManager m_textureManager;

	GameObject m_go;
	Player m_player;
};

#endif