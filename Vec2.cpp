#include "Vec2.h"

Vec2::Vec2() {}

Vec2::Vec2(float xin, float yin)
	:x(xin), y(yin) {}

Vec2& Vec2::add(const Vec2& v)
{
	x += v.x;
	y += v.y;
		 
	return *this;
}

Vec2& Vec2::sub(const Vec2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

Vec2& Vec2::scale(float s)
{
	x *= s;
	y *= s;

	return *this;
}

Vec2& Vec2::normalize()
{
	if (float len = length(); len != 0)
	{
		x /= len;
		y /= len;
	}

	return *this;
}

float Vec2::length() const
{
	return sqrtf(x * x + y * y);
}

float Vec2::dist(const Vec2& v) const
{
	return (*this - v).length();
}


Vec2& Vec2::rotate(float angle)
{
	float temp_x = x;

	x = x * cosf(angle) - y * sinf(angle);
	y = temp_x * sinf(angle) + y * cosf(angle);

	return *this;
}

Vec2 Vec2::operator + (const Vec2& v) const
{
	return Vec2(x + v.x, y + v.y);
}

void Vec2::operator += (const Vec2& v) 
{
	x += v.x;
	y += v.y;
}

Vec2 Vec2::operator * (float s) const
{
	return Vec2(x * s, y * s);
}

void Vec2::operator *= (float s) 
{
	x *= s;
	y *= s;
}

Vec2 Vec2::operator - (const Vec2& v) const
{
	return Vec2(x - v.x, y - v.y);
}

void Vec2::operator -= (const Vec2& v)
{
	x -= v.x;
	y -= v.y;
}

Vec2 Vec2::operator / (const float s) const
{
	return Vec2(x / s, y / s);
}

void Vec2::operator /= (const float s)
{
	x /= s;
	y /= s;
}

bool Vec2::operator == (const Vec2& v) const
{
	return (x == v.x) && (y == v.y);
}

bool Vec2::operator != (const Vec2& v) const
{
	return (x != v.x) || (y != v.y);
}
