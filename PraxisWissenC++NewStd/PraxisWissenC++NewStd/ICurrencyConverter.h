#pragma once

class ICurrencyConverter {
public:
	ICurrencyConverter() {}
	virtual ~ICurrencyConverter() {}
	virtual long double getConversionFactor() const = 0;
};