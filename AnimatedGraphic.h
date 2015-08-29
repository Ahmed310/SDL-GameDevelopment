#ifndef ANIMATED_GRAPHICS_H
#define ANIMATED_GRAPHICS_H

#include "SDL_GameObject.h"
#include "SDL2/SDL.h"
class AnimatedGraphic : public SDL_GameObject
{
public:
	AnimatedGraphic(const LoaderParams* params, int animSpeed, int frameNum)
		:SDL_GameObject(), m_animSpeed(animSpeed), m_numFrames(frameNum)
	{}

	void Update()
	{
		m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
	}

private:
	int m_animSpeed;
	int m_numFrames;
};

#endif