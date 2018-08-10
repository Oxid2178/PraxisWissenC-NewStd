#include "stdafx.h"
#include "UserOfConvService.h"


UserOfConvService::UserOfConvService(const std::shared_ptr<ICurrencyConverter> &convService) : _convService(convService)
{
}

void UserOfConvService::doSomething()
{
	long double convFactor = _convService->getConversionFactor();
	std::cout << "The conversion factor is: " << convFactor << '\n';
}