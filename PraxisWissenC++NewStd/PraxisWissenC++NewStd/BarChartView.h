#pragma once

#include "IObserver.h"
#include "SpreadsheetModel.h"

class BarChartView : public IObserver
{
private:
    SpreadsheetModel& model;

public:
    BarChartView(SpreadsheetModel& theModel) :
        model{ theModel } {}
    
    virtual int getId() override
    {
        return 2;
    }

    virtual void update() override
    {
        std::cout << "Update of BarChartView." << "\n";
    }
};

