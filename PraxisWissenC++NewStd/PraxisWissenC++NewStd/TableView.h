#pragma once

#include "IObserver.h"
#include "SpreadsheetModel.h"

class TableView : public IObserver
{
private:
    SpreadsheetModel& model;

public:
    TableView(SpreadsheetModel& theModel) :
        model{ theModel } {}
    
    virtual int getId() override
    {
        return 1;
    }

    virtual void update() override
    {
        std::cout << "Update of TableView." << "\n";
    }
};

