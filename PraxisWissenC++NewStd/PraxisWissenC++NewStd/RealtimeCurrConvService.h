#pragma once

#include "stdafx.h"
#include "ICurrencyConverter.h"

class RealtimeCurrencyConversionService : public ICurrencyConverter 
{
private:
	long double conversionFactor{ 0.5 };

public:
	virtual long double getConversionFactor() const override;
};