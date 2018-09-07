#pragma once

#include "ILoggingFacility.h"
#include "StandardOutputLoggerImpl.h"
#include "FileSystemLoggerImpl.h"

#include <fstream>

using namespace std;

class LoggerFactory
{
private:
    enum class OutputTarget : int
    {
        STDOUT,
        FILE
    };

public:
    explicit LoggerFactory(string configFileName) :
        configFileName {configFileName} {}

    LoggerPtr create() const 
    {
        const string configFileContent = readConfigFile();
        OutputTarget outputTarget = evalConfig(configFileContent);
        return createLogger(outputTarget);
    }

private:
    string readConfigFile() const
    {
        ifstream filestream(configFileName);
        return string(istreambuf_iterator<char>(filestream), istreambuf_iterator<char>());
    }


    OutputTarget evalConfig(string configFileContent) const
    {
        // Evaluate the content of the evaluation file...
        return OutputTarget::STDOUT;
    }

    LoggerPtr createLogger(OutputTarget outputTarget) const 
    {
        switch (outputTarget)
        {
        case OutputTarget::FILE :
            return make_shared<FileSystemLoggerImpl>();
        case OutputTarget::STDOUT :
        default:
            return make_shared<StandardOutputLoggerImpl>();
        }
    }



    const string configFileName;
};

