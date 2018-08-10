#pragma once
class Kap3Templates
{
public:
	Kap3Templates();
	virtual ~Kap3Templates();

	void kap3_1variablenTemplates();
	template<class T>
	static T var;
	template <typename T>
	inline T const& Max(T const& a, T const& b)
	{
		return a < b ? b : a;
	}

	template<int digit>
	int BinToNumber()
	{
		return digit;
	}

	template<int firstDigit, int secondDigit, int... restDigits>
	int BinToNumber()
	{
		return firstDigit + BinToNumber<2 * secondDigit, 2 * restDigits...>();
	}
};

