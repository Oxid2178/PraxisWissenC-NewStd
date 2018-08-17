#pragma once

class IAccount
{
public:
	virtual ~IAccount() = default;
	virtual std::string getAccountName() const = 0;
};

using IAccountPtr = std::shared_ptr<IAccount>;