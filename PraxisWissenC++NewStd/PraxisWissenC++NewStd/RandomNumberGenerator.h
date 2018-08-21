#pragma once

#include <random>

template<typename NUMTYPE>
class RandomNumberGenerator
{
private:
	std::random_device randomDevice;
	std::uniform_int_distribution<NUMTYPE> distribution;
	std::mt19937_64 mersenneTwisterEngine;

public:
	RandomNumberGenerator()
	{
		mersenneTwisterEngine.seed(randomDevice());
	}
	NUMTYPE operator()()
	{
		return distribution(mersenneTwisterEngine);
	}
};

