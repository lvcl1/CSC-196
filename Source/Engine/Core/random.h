#pragma once
#include <random>
namespace kiko
{
	inline void seedRandom(unsigned int seed) { srand(seed); }
	inline int random() { return rand(); }
	inline int random(unsigned int max) { return rand() % max; }
	inline int random(unsigned int min, unsigned int max) { if (min > max) { int temp = min; min = max; max = temp; } return min + random((max - min) + 1); }

	inline float randomf() { return random() / (float)RAND_MAX; }
	inline float randomf(float max) { return randomf() * max; }
	inline float randomf(float max, float min) { if (min > max) { int temp = min; min = max; max = temp; } return min + randomf((max - min) + 1); }
}