#ifndef _Game_H
#define _GAME_H

#include "SDL2/SDL.h"

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
};

#endif