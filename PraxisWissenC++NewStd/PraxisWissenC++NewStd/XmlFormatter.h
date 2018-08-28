#pragma once
#include "Formatter.h"
class XmlFormatter : public Formatter
{
public:
	virtual string format() const override
	{
		stringstream formattedString{};
		formattedString << 
			"<customer id=\"" << customerId << "\">\n" <<
			" <forename>" << forename << "</forename>\n" <<
			" <surname>" << surname << "</surname>\n" <<
			" <street>" << street << "</street>\n" <<
			" <zipcode>" << zipCode << "</zipcode>\n" <<
			" <city>" << city << "</city>\n" <<
			"</customer>\n";
		return formattedString.str();
	}
};

