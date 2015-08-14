#ifndef ENEMY_H
#define ENEMY_H

#include "SDL_GameObject.h"
#include <string>

class Enemy : public SDL_GameObject
{
public:
	Enemy(const LoaderParams* params);
	~Enemy();

public:
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
};

#endif