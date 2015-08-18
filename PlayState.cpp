#include "PlayState.h"

#include <iostream>
const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState()
{
}


PlayState::~PlayState()
{
}


void PlayState::Update()
{}
void PlayState::Render()
{}
bool PlayState::OnEnter()
{
	std::cout << "PlayState Enters ! \n";
	return true;
}
bool PlayState::OnExit()
{
	std::cout << "PlayState Exit ! \n";
	return true;
}