#pragma once

#include "DrawCommandProcessor.h"
#include "DrawingProcessor.h"
#include "CompositeCommand.h"
#include "Point.h"
#include "IUndoableCommand.h"
#include "DrawCircleCmdImpl.h"
#include "UndoCommand.h"

class CompositeClient
{
public:
	void run() 
	{
		DrawCommandProcessor drawCmdProc{};
		DrawingProcessor drawingProc{};

		auto macroReader = std::make_shared<CompositeCommand>();

		Point circleCenterPoint{};
		DrawCommandPtr drawCircleCmd = std::make_shared<DrawCircleCmdImpl>(drawingProc, circleCenterPoint, 10);
		drawCmdProc.execute(drawCircleCmd);
		macroReader->addCommand(drawCircleCmd);

		drawCmdProc.execute(macroReader);

		DrawCommandPtr undoCmd = std::make_shared<UndoCommand>(drawCmdProc);
		drawCmdProc.execute(undoCmd);
	}
};

