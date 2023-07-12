#pragma once
#include <cmath>
#include <sstream>
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

		float langthSqr() const { return (X * X) + (Y * Y); }
		float langth() const { return sqrt(langthSqr()); }
		float distanceSqr(const vec2& v) const { return(v - *this).langthSqr(); }
		float distance(const vec2& v) const { return(v - *this).langth(); }
		Vector2 Normalized() const { return *this/langth(); }
		void Normalize() { *this /= langth(); }
		float angle() const { return std::atan2f(Y, X); }
		Vector2 Rotate(float rad) const;
	private:

	};
	inline Vector2 Vector2::Rotate(float rad) const {
		float _x = X * std::cos(rad) - Y * std::sin(rad);
		float _y = X * std::sin(rad) + Y * std::cos(rad);
		return { _x,_y };
	}
	std::istream& operator >>(std::istream& strem, Vector2& v) {
		std::string line;
		std::getline(strem, line);
		// { ##, ## }
		std::string xs = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
		v.X = std::stof(xs);

		std::string ys = line.substr(line.find(",") + 1, line.find("}") - (line.find(",") + 1));
		v.Y = std::stof(ys);
		return strem;
	}
	using vec2 = Vector2;
}