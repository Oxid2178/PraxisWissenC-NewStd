#pragma once
class IProcessService
{
public:
    virtual ~IProcessService() = default;

    virtual void doProcess() = 0;
};

using IProcessServicePtr = std::shared_ptr<IProcessService>;