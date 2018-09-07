#pragma once

#include "IObserver.h"
#include "SpreadsheetModel.h"

class PieChartView : public IObserver
{
private:
    SpreadsheetModel& model;

public:
    PieChartView(SpreadsheetModel& theModel) :
        model{ theModel } {}
    
    virtual int getId() override
    {
        return 3;
    }

    virtual void update() override
    {
        std::cout << "Update of PieChartView." << "\n";
    }
};

