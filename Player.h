#ifndef PLAYER_H
#define PLAYER_H

#include "SDL_GameObject.h"

class Player : public SDL_GameObject
{
public:
	Player(const LoaderParams* params);
	~Player();

	virtual void Draw();
	virtual void Update();
	virtual void Clean();
};

#endif
