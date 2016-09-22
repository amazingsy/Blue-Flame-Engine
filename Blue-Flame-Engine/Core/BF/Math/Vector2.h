#pragma once
#include <iostream>

namespace BF
{
	namespace Math
	{
		struct Vector2
		{
			float x = 0.0f, y = 0.0f;

			Vector2() { }
			Vector2(const float &value) : x(value), y(value) { }
			Vector2(const float &x, const float &y) : x(x), y(y) { }

			friend const Vector2 operator+(const Vector2 &leftVector, const Vector2 &rightVector) { return Vector2(leftVector.x + rightVector.x, leftVector.y + rightVector.y); }
			friend const Vector2 operator-(const Vector2 &leftVector, const Vector2 &rightVector) { return Vector2(leftVector.x - rightVector.x, leftVector.y - rightVector.y); }
			friend const Vector2 operator*(const Vector2 &leftVector, const Vector2 &rightVector) { return Vector2(leftVector.x * rightVector.x, leftVector.y * rightVector.y); }
			friend const Vector2 operator/(const Vector2 &leftVector, const Vector2 &rightVector) { return Vector2(leftVector.x / rightVector.x, leftVector.y / rightVector.y); }

			friend std::ostream& operator<<(std::ostream& os, const Vector2& vector) { return os << "{" << vector.x << ", " << vector.y << "}"; }
		};
	}
}