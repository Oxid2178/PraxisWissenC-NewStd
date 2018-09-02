#pragma once

#include "DrawCommandProcessor.h"
#include "DrawCircleCmdImpl.h"
#include "UndoCommand.h"

class DrawClient
{
public:
    void run()
    {
		DrawCommandProcessor drawCmdProc{};
		DrawingProcessor drawingProc{};
		Point point{};

        DrawCommandPtr drawCircleCmd = std::make_shared<DrawCircleCmdImpl>(drawingProc,  point, 23.5);
        
        drawCmdProc.execute(drawCircleCmd);

		DrawCommandPtr undoCmd = std::make_shared<UndoCommand>(drawCmdProc);
		drawCmdProc.execute(undoCmd);
    }
};

