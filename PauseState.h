#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include <vector>
#include "GameState.h"
#include <string>

class GameObject;				// forward declearation

class PauseState : public GameState
{
public:

	virtual void Update();
	virtual void Render();
	virtual bool OnEnter();
	virtual bool OnExit();

	virtual std::string GetStateID() const { return s_pauseID; }

private:
	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;

	static void PauseToMain();
	static void ResumeToPlay();
};

#endif