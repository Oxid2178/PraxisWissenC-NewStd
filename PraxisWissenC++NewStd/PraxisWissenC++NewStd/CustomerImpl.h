#pragma once

#include "IOwner.h"
#include "Account2.h"

class CustomerImpl : public IOwner
{
private:
	AccountPtr customerAccount;
	std::string customerName = "Alessio";

public:
	CustomerImpl();
	~CustomerImpl();
	void setAccount(AccountPtr account);
	virtual std::string getCustomerName() const override;
};

using CustomerPtr = std::shared_ptr<CustomerImpl>;