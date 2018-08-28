#pragma once

#include "ILoggingFacility.h"

class CustomerRepository
{
private:
	Logger logger;

public:
	CustomerRepository() = delete;

	explicit CustomerRepository(const Logger& loggingService) : logger{loggingService} {}

	std::string findCustomerById(const int customId)
	{
		logger->writeInfoEntry("Starting to search for a customer specified by a given unique...");
		return "The custom is Mario";
	}

	void setLoggingService(const Logger& loggingService)
	{
		logger = loggingService;
	}
};


