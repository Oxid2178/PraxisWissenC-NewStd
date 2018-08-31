#pragma once

#include "DrawCommandProcessor.h"
#include "DrawCircleCmdImpl.h"
#include "UndoCommand.h"

class DrawClient
{
public:
    void run()
    {
        
        //auto drawCmdProcPtr{ std::make_shared<DrawCommandProcessor>() };
        //auto undoCmdPtr{ std::make_shared<UndoCommand>(drawCmdProcPtr) };
        //auto drawingProcPtr{ std::make_shared<DrawingProcessor>() };
        //auto pointPtr{ std::make_shared<Point>() };

        DrawCommandPtr drawCircleCmd = std::make_shared<DrawCircleCmdImpl>(drawingProcPtr,  pointPtr, 23.5);
        
        
        
        drawCmdProcPtr->execute(drawCircleCmd);
    }
};

