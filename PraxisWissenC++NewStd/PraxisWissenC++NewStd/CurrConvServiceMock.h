#pragma once

#include "ICurrencyConverter.h"

class CurrConvServiceMock : public ICurrencyConverter
{
private:
	long double conversionFactor{ 0.4 };

public:
	virtual long double getConversionFactor() const override;
	void setConversionFactor(const long double value);
};

