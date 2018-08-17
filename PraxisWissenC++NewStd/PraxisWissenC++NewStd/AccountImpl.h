#pragma once

#include "IOwner.h"
#include "IAccount.h"

class AccountImpl : public IAccount
{
private:
	IOwnerPtr owner;
	std::string accountName = "ZKBAccount";

public:
	AccountImpl();
	~AccountImpl();
	void setOwner(IOwnerPtr owner);
	virtual std::string getAccountName() const override;
};

using AccountPtr = std::shared_ptr<AccountImpl>;