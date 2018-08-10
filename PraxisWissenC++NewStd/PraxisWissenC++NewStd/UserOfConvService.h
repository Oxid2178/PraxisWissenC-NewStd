#pragma once

#include "ICurrencyConverter.h"

class UserOfConvService
{
private:
	std::shared_ptr<ICurrencyConverter> _convService;

public:
	UserOfConvService() = delete;
	UserOfConvService(const std::shared_ptr<ICurrencyConverter> &convService);
	void doSomething();
};

