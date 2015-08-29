#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "LoaderParams.h"

class GameObject
{
public:

	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Clean() = 0; 
	// new load function
	virtual void load(const LoaderParams* pParams) = 0;

protected:

	GameObject(){}
	virtual ~GameObject(){}

};

#endif