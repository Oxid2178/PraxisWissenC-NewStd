#pragma once
#include "DrawCommandProcessor.h"

class UndoCommand : public IUndoableCommand
{
private:
	DrawCommandProcessor& receiver;

public:
	explicit UndoCommand(DrawCommandProcessor& receiver) noexcept
		: receiver{ receiver } {}

	virtual void execute() override
	{
		receiver.undoLastCmd();
	}

	virtual void undo() override
	{
		// Intentionally left blank, because an undo should not be undone.
	}

};

