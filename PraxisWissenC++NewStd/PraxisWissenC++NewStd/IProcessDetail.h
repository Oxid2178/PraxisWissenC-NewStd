#pragma once
class IProcessDetail
{
public:
    virtual ~IProcessDetail() = default;

    virtual void doDetailProcess() = 0;
};

using IProcessDetailPtr = std::shared_ptr<IProcessDetail>;