#pragma once

#include "IProcessDetail.h"

class ProcessDetail : public IProcessDetail
{
public:
    ProcessDetail();

    virtual void doDetailProcess() override
    {
        std::cout << "Detail process performed!";
    }
};

