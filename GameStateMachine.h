#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H

#include "GameState.h"
#include <vector>

class GameStateMachine
{
public:
	

	void PushState(GameState* state);
	void ChangeState(GameState* state);
	void PopState();
	void Update();
	void Render();

private:
	std::vector<GameState*> m_gameStates;

};

#endif