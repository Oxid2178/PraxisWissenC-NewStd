#pragma once
class ILoggingFacility
{

public:
	virtual ~ILoggingFacility() = default;
	virtual void writeInfoEntry(std::string entry) = 0;
	virtual void writeWarnEntry(std::string entry) = 0;
	virtual void writeErrorEntry(std::string entry) = 0;
};

using LoggerPtr = std::shared_ptr<ILoggingFacility>;