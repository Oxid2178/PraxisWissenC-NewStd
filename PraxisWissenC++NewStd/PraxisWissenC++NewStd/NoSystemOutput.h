#pragma once
#include "ILoggingFacility.h"

class NoSystemOutput : public ILoggingFacility
{
private:
    bool configParamValid{ false };

public:
	virtual void writeInfoEntry(std::string entry) override
	{
		
	}

	virtual void writeWarnEntry(std::string entry) override
	{
		
	}

	virtual void writeErrorEntry(std::string entry) override
	{
		
	}

    virtual const bool isConfigParamValid() override
    {
        return configParamValid;
    }
};


