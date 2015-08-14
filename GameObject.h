#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include"SDL2/SDL.h"
#include<string>

class GameObject
{
public:
	GameObject();
	~GameObject();

public:

	void Load(int x, int y, int w, int h, std::string textureID);

	void Draw(SDL_Renderer* renderer);
	void Update();
	void Clean();

protected:

	std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;

	int m_x;
	int m_y;

	int m_width;
	int m_height;
};

#endif