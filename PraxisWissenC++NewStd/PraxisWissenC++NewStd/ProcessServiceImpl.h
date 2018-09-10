#pragma once

#include "IProcessService.h"
#include "IProcessDetail.h"

class ProcessServiceImpl : public IProcessService
{
private:
    IProcessDetailPtr processDetail;

public:
    explicit ProcessServiceImpl(const IProcessDetailPtr &processDetail) :
        processDetail{ processDetail } {}

    virtual void doProcess() override
    {
        processDetail->doDetailProcess();
    }
};

