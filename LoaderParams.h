#ifndef LOADER_PARAMS_H
#define LOADER_PARAMS_H

#include <string>

class LoaderParams
{
public:
	LoaderParams(int x, int y, int w, int h, std::string textureId)
		: m_x(x), m_y(y), m_width(w), m_height(h), m_textureID(textureId)
	{}

	inline int GetX() const { return m_x; }
	inline int GetY() const { return m_y; }
	inline int GetWidth() const { return m_width; }
	inline int GetHeight() const { return m_height; }
	inline std::string GetTextureID() const { return m_textureID; }

private:
	int m_x;
	int m_y;

	int m_width;
	int m_height;

	std::string m_textureID;

};

#endif