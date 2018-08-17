#pragma once

#include "IOwner.h"
#include "IAccount.h"

class CustomerImpl : public IOwner
{
private:
	IAccountPtr customerAccount;
	std::string customerName = "Alessio";

public:
	CustomerImpl();
	~CustomerImpl();
	void setAccount(IAccountPtr account);
	virtual std::string getCustomerName() const override;
};

using CustomerPtr = std::shared_ptr<CustomerImpl>;