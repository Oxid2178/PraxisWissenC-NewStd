#pragma once
#include "Formatter.h"
class JsonFormatter : public Formatter
{
private:
	static constexpr const int const END_OF_PROPERTY{'\',\n'};

public:
	virtual std::string format() const override 
	{
		std::stringstream formattedString { };
		formattedString <<
			"{\n" <<
			" \"CustomerId : \""	<< customerId	<< END_OF_PROPERTY <<
			" \"Forename: \""		<< forename		<< END_OF_PROPERTY <<
			" \"Surname: \""		<< surname		<< END_OF_PROPERTY <<
			" \"Street: \""			<< street		<< END_OF_PROPERTY <<
			" \"ZIP code: \""		<< zipCode		<< END_OF_PROPERTY <<
			" \"City: \""			<< city			<< "\"\n" <<
			"}\n";
		return formattedString.str();
	}
};

