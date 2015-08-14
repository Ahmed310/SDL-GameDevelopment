#ifndef SDL_GAME_OBJECT_H
#define SDL_GAME_OBJECT_H

#include "GameObject.h"

class SDL_GameObject : public GameObject
{
public:
	SDL_GameObject(const LoaderParams* params);

	virtual void Draw();
	virtual void Update();
	virtual void Clean();

	~SDL_GameObject();

protected:
	int m_x;
	int m_y;

	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;
};

#endif