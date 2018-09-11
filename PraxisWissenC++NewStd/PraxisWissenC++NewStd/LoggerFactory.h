#pragma once

#include "ILoggingFacility.h"
#include "StandardOutputLoggerImpl.h"
#include "FileSystemLoggerImpl.h"
#include "NoSystemOutput.h"

#include <fstream>

using namespace std;

class LoggerFactory
{
private:
    enum class OutputTarget : int
    {
        STDOUT,
        FILE,
        NOCONFIG
    };

    const string configFileName;

public:
    explicit LoggerFactory(string configFileName) :
        configFileName {configFileName} {}

    LoggerPtr create() const
    {
        const string configFileContent = readConfigFile();
        OutputTarget outputTarget = evalConfig(configFileContent);
        if (createLogger(outputTarget)->isConfigParamValid())
        {
            return createLogger(outputTarget);
        }
        else
        {
            throw ("Konfigurationsdatei nicht vorhanden oder enthaelt keinen gueltigen Konfigurationsparameter!\n");
        }
    }

private:
    string readConfigFile() const
    {
        ifstream filestream(configFileName);
        return string(istreambuf_iterator<char>(filestream), istreambuf_iterator<char>());
    }


    OutputTarget evalConfig(string configFileContent) const
    {
        if (configFileContent == "FileSystem")
        {
            return OutputTarget::FILE;
        }
        else if (configFileContent == "StandardOutput")
        {
            return OutputTarget::STDOUT;
        }
        else
        {
            return OutputTarget::NOCONFIG;
        }

        
    }

    LoggerPtr createLogger(OutputTarget outputTarget) const 
    {
        switch (outputTarget)
        {
            case OutputTarget::FILE :
                return make_shared<FileSystemLoggerImpl>();
            case OutputTarget::STDOUT :
                return make_shared<StandardOutputLoggerImpl>();
            default:
                return make_shared<NoSystemOutput>();
                
        }
    }
};

