#ifndef PLAYER_H
#define PLAYER_H

#include "SDL_GameObject.h"
#include "GameObjectFactory.h"

class Player : public SDL_GameObject
{
public:
	Player();
	
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
	void load(const LoaderParams *params);

private :
	void HandleInput();
};



class PlayerCreator : public BaseCreator
{
	GameObject* CreateGameObject() const
	{
		return new Player();
	}
};



#endif
