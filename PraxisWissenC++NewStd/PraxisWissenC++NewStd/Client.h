#pragma once

#include "Server.h"
#include "ICommand.h"
#include "HelloWorldOutputCmdImpl.h"
#include "WaitCmdImpl.h"

class Client
{
public:
	void run()
	{
		Server theServer{};

		const unsigned int SERVER_DELAY_TIMESPAN{ 3000 };

		CommandPtr helloWorldOutputCmd = std::make_shared<HelloWorldOutputCmdImpl>();
		theServer.acceptCommand(helloWorldOutputCmd);

		CommandPtr waitCommand = std::make_shared<WaitCmdImpl>(SERVER_DELAY_TIMESPAN);
		theServer.acceptCommand(waitCommand);

		theServer.acceptCommand(helloWorldOutputCmd);
	}
};