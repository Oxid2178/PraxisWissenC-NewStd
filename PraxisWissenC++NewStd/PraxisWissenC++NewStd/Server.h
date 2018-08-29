#pragma once

#include "ICommand.h"

class Server
{
public:
	void acceptCommand(const CommandPtr& command)
	{
		command->execute();
	}
};

