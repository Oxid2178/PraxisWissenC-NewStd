#pragma once
class ICommand
{
public:
	virtual ~ICommand() = default;
	virtual void execute() = 0;
};

using CommandPtr = std::shared_ptr<ICommand>;

