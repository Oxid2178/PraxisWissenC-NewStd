#pragma once
class GCDwithTemplate
{
public:
//	GCDwithTemplate();
//	~GCDwithTemplate();

public:
	template<unsigned int x, unsigned int y>
	struct GreatestCommonDivisor 
	{
		static const unsigned int result = GreatestCommonDivisor<y, x % y>::result;
	};

	template<unsigned int x>
	struct GreatestCommonDivisor<x, 0>
	{
		static const unsigned int result = x;
	};

	static constexpr unsigned int greatestCommonDivisor(const unsigned int x, const unsigned int y) noexcept
	{
		return y == 0 ? x : greatestCommonDivisor(y, x % y);
	}
};

