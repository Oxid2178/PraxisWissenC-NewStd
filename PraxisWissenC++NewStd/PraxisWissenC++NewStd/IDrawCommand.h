#pragma once
class IDrawCommand
{
public:
	virtual ~IDrawCommand() = default;
	virtual void execute() = 0;
};

