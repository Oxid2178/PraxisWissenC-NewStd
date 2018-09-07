#pragma once

#include "Subject.h"

class SpreadsheetModel : public Subject
{
public:
    void changeCellValue(std::string column, const int row, const double value)
    {
        std::cout << "Cell [" << column << ", " << row << "]= " << value << std::endl;
        // Change value of a spreadsheet cell, and then...
        notifyAllObserver();
    }
};

