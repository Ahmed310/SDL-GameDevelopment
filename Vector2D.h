#ifndef VECTOR2D_H
#define VECTOR2D_H


#include<math.h>

class Vector2D
{
public:
	Vector2D(float x, float y)
		: m_x(x), m_y(y)
	{}

	inline float GetX(){ return m_x; }
	inline float GetY(){ return m_y; }

	void SetX(float x){ m_x = x; }
	void SetY(float y){ m_y = y; }

	float Length() { return sqrt(m_x * m_x + m_y * m_y); }

	void normalize()
	{
		float l = Length();
		if (l > 0) // we never want to attempt to divide by 0
		{
			(*this) *= 1 / l;
		}
	}

	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}

	friend Vector2D& operator += (Vector2D& v1, Vector2D& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	Vector2D operator*(float scalar)
	{
		return Vector2D(m_x * scalar, m_y * scalar);
	}

	Vector2D& operator *= (float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;

		return *this;
	}

	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}

	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}

	Vector2D operator/(float scalar)
	{
		return Vector2D(m_x / scalar, m_y / scalar);
	}
	Vector2D& operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;
	
		return *this;
	}


private:
	float m_x;
	float m_y;

};



#endif