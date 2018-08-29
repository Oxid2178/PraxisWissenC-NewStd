#pragma once

#include "Server.h"
#include "ICommand.h"
#include "HelloWorldOutputCmdImpl.h"

class Client
{
public:
	void run()
	{
		Server theServer{};
		CommandPtr helloWorldOutputCmd = std::make_shared<HelloWorldOutputCmdImpl>();
		theServer.acceptCommand(helloWorldOutputCmd);
	}
};

