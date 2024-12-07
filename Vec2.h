#pragma once

#include <math.h>

class Vec2
{
public:
	float x = 0, y = 0;

	Vec2();
	Vec2(float xin, float yin);

	bool operator== (const Vec2& v) const;
	bool operator!= (const Vec2& v) const;

	Vec2 operator + (const Vec2& v) const;
	Vec2 operator - (const Vec2& v) const;
	Vec2 operator / (const float s) const;
	Vec2 operator * (const float s) const;

	void operator += (const Vec2& v);
	void operator -= (const Vec2& v);
	void operator *= (const float s);
	void operator /= (const float s);

	Vec2& add(const Vec2& v);
	Vec2& sub(const Vec2& v);
	Vec2& scale(const float s);
	Vec2& normalize();
	Vec2& rotate(float angle);
	float length() const;
	float dist(const Vec2& v) const;
};