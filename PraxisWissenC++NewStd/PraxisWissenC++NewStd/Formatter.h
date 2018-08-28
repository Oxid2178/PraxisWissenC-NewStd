#pragma once

using namespace std;

class Formatter
{
protected:
	string customerId{ "000000" };
	string forename{ "n/a" };
	string surname{ "n/a" };
	string street{ "n/a" };
	string zipCode{ "n/a" };
	string city{ "n/a" };

public:
	virtual ~Formatter() = default;

	Formatter& withCustomerId(std::string customerId)
	{
		this->customerId = customerId;
		return *this;
	}

	Formatter& withForename(std::string forename)
	{
		this->forename = forename;
		return *this;
	}

	Formatter& withSurname(std::string surename)
	{
		this->surname = surename;
		return *this;
	}

	Formatter& withStreet(std::string street)
	{
		this->street = street;
		return *this;
	}

	Formatter& withZipCode(std::string zipCode)
	{
		this->zipCode = zipCode;
		return *this;
	}

	Formatter& withCity(std::string city)
	{
		this->city = city;
		return *this;
	}

	virtual string format() const = 0;
};

using FormatPtr = unique_ptr<Formatter>;

