#pragma once
#include "ICommand.h"
class HelloWorldOutputCmdImpl : public ICommand
{
public:
	virtual void execute() override
	{
		std::cout << "Hello World!" << "\n";
	}
};

