#pragma once
class ToSquare
{
public:
	constexpr int operator()(const int value) const noexcept
	{
		return value * value;
	}
};

