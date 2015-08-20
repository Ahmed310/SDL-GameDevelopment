#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.h"
#include <string>
#include <vector>

class GameObject;				// forward declearation
class SDL_GameObject;

class PlayState : public GameState
{
public:
	
	virtual void Update();
	virtual void Render();
	virtual bool OnEnter();
	virtual bool OnExit();

	virtual std::string GetStateID() const { return s_playID; }

	bool CheckCollision(SDL_GameObject* p1, SDL_GameObject* p2);

private:
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;

};

#endif