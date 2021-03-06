#pragma once

#include "ILoggingFacility.h"

class StandardOutputLoggerImpl : public ILoggingFacility
{
private:
    bool configParamValid{ true };

public:
	virtual void writeInfoEntry(std::string entry) override
	{
		std::cout << "[INFO] " << entry << std::endl;
	}

	virtual void writeWarnEntry(std::string entry) override
	{
		std::cout << "[WARNING] " << entry << std::endl;
	}

	virtual void writeErrorEntry(std::string entry) override
	{
		std::cout << "[ERROR] " << entry << std::endl;
	}

    virtual const bool isConfigParamValid() override
    {
        return configParamValid;
    }
};

