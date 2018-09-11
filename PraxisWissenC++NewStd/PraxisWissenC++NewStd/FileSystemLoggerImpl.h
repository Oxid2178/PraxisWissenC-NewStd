#pragma once

#include "ILoggingFacility.h"

class FileSystemLoggerImpl : public ILoggingFacility
{
private:
    bool configParamValid{ true };

public:
	virtual void writeInfoEntry(std::string entry) override
	{
		std::cout << "[INFO IN FILESYSTEM] " << entry << std::endl;
	}

	virtual void writeWarnEntry(std::string entry) override
	{
		std::cout << "[WARNING IN FILESYSTEM] " << entry << std::endl;
	}

	virtual void writeErrorEntry(std::string entry) override
	{
		std::cout << "[ERROR IN FILESYSTEM] " << entry << std::endl;
	}

    virtual const bool isConfigParamValid() override
    {
        return configParamValid;
    }
};


