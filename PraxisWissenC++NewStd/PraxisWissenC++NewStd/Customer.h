#pragma once

class Account;

class Customer
{
public:
	Customer();
	~Customer();
	void setAccount(Account *account);

private:
	Account *customerAccount;
	std::string getCustomerName() const;
};

