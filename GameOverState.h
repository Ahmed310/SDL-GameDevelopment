#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H

#include "GameState.h"
#include <vector>
#include <string>

class GameObject;

class GameOverState : public GameState
{
public:
	virtual void Update();
	virtual void Render();
	virtual bool OnEnter();
	virtual bool OnExit();

	virtual std::string GetStateID() const { return s_gameOverID; }
private:
	static void GameOverToMain();
	static void RestartPlay();
	static const std::string s_gameOverID;
	std::vector<GameObject*> m_gameObjects;
};

#endif
