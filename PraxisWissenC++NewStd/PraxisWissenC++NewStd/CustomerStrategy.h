#pragma once

#include "Formatter.h"

class CustomerStrategy
{
private:
	string customerId{"123"};
	string forename{"Antonio"};
	string surname{"Carlucci"};
	string zipCode{ "8712" };
	string city{ "Staefa" };

public:
	string getAsFormattedString(const FormatPtr& formatter) const 
	{
		return formatter->
			withCustomerId(customerId).
			withForename(forename).
			withSurname(surname).
			withZipCode(zipCode).
			withCity(city).
			format();
	}
};

