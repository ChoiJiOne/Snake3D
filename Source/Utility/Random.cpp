#include "Utility/Random.h"

int32_t Random::GenerateRandomInt(int32_t minValue, int32_t maxValue)
{
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<int32_t> distribution(std::min<int32_t>(minValue, maxValue), std::max<int32_t>(minValue, maxValue));

	return distribution(generator);
}

float Random::GenerateRandomFloat(float minValue, float maxValue)
{
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_real_distribution<float> distribution(std::min<float>(minValue, maxValue), std::max<float>(minValue, maxValue));

	return distribution(generator);
}