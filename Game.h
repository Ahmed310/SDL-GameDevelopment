#ifndef _Game_H
#define _GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "TextureManager.h"
#include "GameObject.h"
#include "GameStateMachine.h"

#include <vector>


#undef main
class Game
{

public:
	void init(const char* title, int x, int y, int w, int h, Uint32 flag);
	void run();
	inline void quit(){ m_running = false; }

	static Game* Instance();
	inline SDL_Renderer* GetRenderer() const{ return m_renderer; }
	inline GameStateMachine* GetStateMachine(){ return m_gameStateMachine; }


	~Game();

private:
	void render();
	void update();
	void handleEvents();
	void clean();

	Game();
	static Game* s_instance;

private:
	bool m_running;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer ;
	const Uint32 FPS = 60;
	const Uint32 DELAY_TIME = 1000 / FPS;
	Uint32 m_frameStart, m_frameTime;

	GameStateMachine* m_gameStateMachine;

	std::vector<GameObject*> m_gameObjects;

};

#endif