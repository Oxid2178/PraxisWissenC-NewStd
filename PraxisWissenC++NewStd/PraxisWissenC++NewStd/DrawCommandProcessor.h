#pragma once
#include "IUndoableCommand.h"
#include <stack>

class DrawCommandProcessor
{
private:
	std::stack<std::shared_ptr<IDrawRevertable>> drawCommandHistory;

public:
	void execute(const DrawCommandPtr& command)
	{
		command->execute();
		drawCommandHistory.push(command); // put on stack
	}

	void undoLastCmd()
	{
		if (drawCommandHistory.empty())
		{
			return;
		}
		drawCommandHistory.top()->undo(); // undo cmd from history stack
		drawCommandHistory.pop();
	}
};

