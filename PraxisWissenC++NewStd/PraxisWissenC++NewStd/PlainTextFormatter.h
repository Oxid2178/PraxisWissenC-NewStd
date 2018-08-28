#pragma once
#include "Formatter.h"

using namespace std;

class PlainTextFormatter : public Formatter
{
public:
	virtual string format() const override
	{
		stringstream formattedString{};
		formattedString << "[" << customerId << "]: "
			<< forename << " " << surname << ", "
			<< street << ", " << zipCode << " "
			<< city << ".";
		return formattedString.str();
	}
};

