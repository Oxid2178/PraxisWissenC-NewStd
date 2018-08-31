#pragma once
class IDrawRevertable
{
public:
	virtual ~IDrawRevertable() = default;
	virtual void undo() = 0;
};

