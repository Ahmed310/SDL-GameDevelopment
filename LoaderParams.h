#ifndef LOADER_PARAMS_H
#define LOADER_PARAMS_H

#include <string>

class LoaderParams
{
public:
	LoaderParams(int x, int y, int w, int h, std::string textureId, int numFrames, int callbackId, int animSpeed)
		: m_x(x), m_y(y), m_width(w), m_height(h), m_textureID(textureId), m_numFrames(numFrames),
		m_callbackID(callbackId), m_animSpeed(animSpeed)
	{}

	inline int GetX() const { return m_x; }
	inline int GetY() const { return m_y; }
	inline int GetWidth() const { return m_width; }
	inline int GetHeight() const { return m_height; }
	inline int GetNumFrames() const { return m_numFrames; }
	inline int GetAnimSpeed() const { return m_animSpeed; }
	inline int GetCallBackID()const { return m_callbackID; }
	inline std::string GetTextureID() const { return m_textureID; }

private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_numFrames;
	int m_animSpeed;
	int m_callbackID;
	std::string m_textureID;

};

#endif