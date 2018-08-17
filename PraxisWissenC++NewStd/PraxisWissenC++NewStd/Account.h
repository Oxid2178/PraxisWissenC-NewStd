#pragma once

class Customer;

class Account
{
public:
	Account();
	~Account();
	void setOwner(Customer *customer);

private:
	Customer *owner;
};

