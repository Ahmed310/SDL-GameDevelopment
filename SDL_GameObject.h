#ifndef SDL_GAME_OBJECT_H
#define SDL_GAME_OBJECT_H

#include "GameObject.h"
#include "Vector2D.h"

class SDL_GameObject : public GameObject
{
public:
	SDL_GameObject();

	virtual void Draw();
	virtual void Update();
	virtual void Clean();
	// new load function
	virtual void load(const LoaderParams* pParams);

	inline Vector2D& GetPosition() { return m_position; }
	inline int GetWidth() { return m_width; }
	inline int GetHeight() { return m_height; }

	~SDL_GameObject();

protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_accelaration;


	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;
	int m_callbackID;

	std::string m_textureID;
};

#endif