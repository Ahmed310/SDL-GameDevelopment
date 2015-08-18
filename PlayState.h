#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.h"

class PlayState : public GameState
{
public:
	PlayState();
	~PlayState();

	virtual void Update();
	virtual void Render();
	virtual bool OnEnter();
	virtual bool OnExit();

	virtual std::string GetStateID() const { return s_playID; }

private:
	static const std::string s_playID;

};

#endif