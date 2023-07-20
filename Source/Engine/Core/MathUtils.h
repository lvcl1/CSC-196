#pragma once
#include <cmath>
namespace kiko {
	constexpr float pi = 3.141592653589793238462643;
	constexpr float Twopi = pi * 2;
	constexpr float halfpi = pi / 2;
	constexpr float RadToDeg(float rad) { return rad * (180 / pi); }
	constexpr float DegToRad(float deg) { return deg * (pi / 180); }
	constexpr int Wrap(int val, int max) { return (val % max) + ((val < 0) ? max : 0); }
	inline float Wrap(float val, float max) { return std::fmod(val, max) + ((val < 0) ? max : 0); }
	template <typename T>
	inline T Max(T a, T b) { return (a > b) ? a : b; }
	template <typename T>
	inline T Min(T a, T b) { return (a < b) ? a : b; }
	template <typename T>
	inline T Clamp(T val, T min, T max) {
		if (min > max) std::swap(min, max);
		return (val < min) ? min : (val > max) ? max : val;
	}
}