#pragma once
#include "IProcessService.h"
#include "ProcessServiceImpl.h"
#include "IProcessDetail.h"
#include "ProcessDetail.h"

class ProcessFactory
{
public:
    IProcessServicePtr createProcessServiceInstance()
    {
        IProcessDetailPtr processDetail = std::make_shared<ProcessDetail>();
        return std::make_shared<ProcessServiceImpl>(processDetail);
    }
};

