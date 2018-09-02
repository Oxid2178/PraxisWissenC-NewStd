#pragma once
#include "IUndoableCommand.h"
class CompositeCommand : public IUndoableCommand
{
private:
	std::vector<DrawCommandPtr> commands;

public:
	void addCommand(DrawCommandPtr& command)
	{
		commands.push_back(command);
	}

	virtual void execute() override
	{
		for (const auto& command : commands)
		{
			command->execute();
		}
	}

	virtual void undo() override
	{
		for (const auto& command : commands)
		{
			command->undo();
		}
	}
};

