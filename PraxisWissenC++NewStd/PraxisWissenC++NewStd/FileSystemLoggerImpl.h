#pragma once

#include "ILoggingFacility.h"

class FileSystemLoggerImpl : public ILoggingFacility
{
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
};


