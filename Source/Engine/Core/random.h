#pragma once
#include <random>
namespace kiko
{
	void seedRandom(unsigned int seed) { srand(seed); }
	int random() { return rand(); }
	int random(unsigned int max) { return rand() % max; }
	int random(unsigned int min, unsigned int max) { if (min > max) { int temp = min; min = max; max = temp; } return min + random((max - min) + 1); }
	
	float randomf() { return random() / (float)RAND_MAX; }
	float randomf(float max) { return randomf() * max; }
	float randomf(float max, float min) { if (min > max) { int temp = min; min = max; max = temp; } return min + randomf((max - min) + 1); }
}