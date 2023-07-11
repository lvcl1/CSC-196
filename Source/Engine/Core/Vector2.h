#pragma once
#include <cmath>
namespace kiko {
	class Vector2
	{
	public:
		float X, Y;
	public:
		Vector2() : X{ 0 }, Y{ 0 } {}
		Vector2(float x) : X{ x }, Y{ 0 } {}
		Vector2(float x, float y) : X{ x }, Y{ y } {}
		Vector2(int x, int y) : X{ (float)x }, Y{ (float)y } {}

		Vector2 operator + (const Vector2& v) const { return Vector2(X + v.X, Y + v.Y); }
		Vector2 operator - (const Vector2& v) const { return Vector2(X - v.X, Y - v.Y); }
		Vector2 operator * (const Vector2& v) const { return Vector2(X * v.X, Y * v.Y); }
		Vector2 operator / (const Vector2& v) const { return Vector2(X / v.X, Y / v.Y); }

		Vector2 operator + (float s) const { return Vector2(X + s, Y + s); }
		Vector2 operator - (float s) const { return Vector2(X - s, Y - s); }
		Vector2 operator * (float s) const { return Vector2(X * s, Y * s); }
		Vector2 operator / (float s) const { return Vector2(X / s, Y / s); }

		Vector2& operator += (const Vector2& v) { X += v.X; Y += v.Y; return *this; }
		Vector2& operator -= (const Vector2& v) { X -= v.X; Y -= v.Y; return *this; }
		Vector2& operator *= (const Vector2& v) { X *= v.X; Y *= v.Y; return *this; }
		Vector2& operator /= (const Vector2& v) { X /= v.X; Y /= v.Y; return *this; }

		float langthsqr() { return (X * X) + (Y * Y); }
		float langth() { return sqrt(langthsqr()); }
		Vector2 Normalized() { return *this/langth(); }
		void Normalize() { *this /= langth(); }
	private:

	};
	using vec2 = Vector2;
}