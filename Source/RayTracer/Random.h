#pragma once
#include <glm/glm.hpp>

inline void seedRandom(uint32_t seed)
{
	srand(seed);
}

inline float random01()
{
	return rand() % RAND_MAX;
}

inline float random(float min, float max)
{
	if (min > max) std::swap(min, max);

	int num;

	do num = random01();
	while (!(num > min && num < max));

	return num;
}
