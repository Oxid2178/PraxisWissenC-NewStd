#pragma once

#include "IProcessDetail.h"

class ProcessDetail : public IProcessDetail
{
public:
    virtual void doDetailProcess() override
    {
        std::cout << "Detail process performed!\n";
    }
};

