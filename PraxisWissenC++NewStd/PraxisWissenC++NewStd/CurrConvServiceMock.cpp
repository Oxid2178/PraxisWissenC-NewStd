#include "stdafx.h"
#include "CurrConvServiceMock.h"

long double CurrConvServiceMock::getConversionFactor() const
{
	return conversionFactor;
}


void CurrConvServiceMock::setConversionFactor(const long double value)
{
	conversionFactor = value;
}
