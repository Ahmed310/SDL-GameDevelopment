#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	void Load(int x, int y, int w, int h, std::string textureID);
	void Draw(SDL_Renderer* renderer);
	void Update();
	void Clean();
};

#endif
