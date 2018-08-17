#pragma once

#include "IOwner.h"

class Account2
{
private:
	IOwnerPtr owner;

public:
	Account2();
	~Account2();
	void setOwner(IOwnerPtr owner);
};

using AccountPtr = std::shared_ptr<Account2>;