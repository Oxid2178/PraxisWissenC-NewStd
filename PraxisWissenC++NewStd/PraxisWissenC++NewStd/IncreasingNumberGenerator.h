#pragma once
class IncreasingNumberGenerator
{
private:
	int number{ 0 };

public:
	int operator()() noexcept
	{
		return number++;
	}
};

