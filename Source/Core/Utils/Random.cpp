#include "Random.h"
#include <cstdlib>
#include <ctime>

bool Random::m_IsInitialized = false;

void Random::SetSeed(int seed) {
	m_IsInitialized = true;
	srand(seed);
}

int Random::Range(int left, int right) {
	Init();
	return left + rand() % (right - left);
}

float Random::Range(float left, float right) {
	Init();
	return left + Next() * (right - left);
}

float Random::Next() {
	Init();
	return (float)rand() / RAND_MAX;
}

void Random::Init() {
	if (!m_IsInitialized) {
		m_IsInitialized = true;

		srand((unsigned int)time(NULL));
	}
}