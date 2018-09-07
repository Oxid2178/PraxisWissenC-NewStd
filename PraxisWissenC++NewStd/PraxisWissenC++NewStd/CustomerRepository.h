#pragma once

#include "ILoggingFacility.h"

class CustomerRepository
{
private:
	LoggerPtr logger;

public:
	CustomerRepository() = delete;

	explicit CustomerRepository(const LoggerPtr& loggingService) : logger{loggingService} {}

	std::string findCustomerById(const int customId)
	{
		logger->writeInfoEntry("Starting to search for a customer specified by a given unique...");
		return "The custom is Mario";
	}

	void setLoggingService(const LoggerPtr& loggingService)
	{
		logger = loggingService;
	}
};


