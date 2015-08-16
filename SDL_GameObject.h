#ifndef SDL_GAME_OBJECT_H
#define SDL_GAME_OBJECT_H

#include "GameObject.h"
#include "Vector2D.h"

class SDL_GameObject : public GameObject
{
public:
	SDL_GameObject(const LoaderParams* params);

	virtual void Draw();
	virtual void Update();
	virtual void Clean();

	~SDL_GameObject();

protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_accelaration;


	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;
};

#endif