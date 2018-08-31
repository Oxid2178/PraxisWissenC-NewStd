#pragma once
#include "IDrawCommand.h"
#include "IDrawRevertable.h"

class IUndoableCommand : public IDrawCommand, public IDrawRevertable {};

using DrawCommandPtr = std::shared_ptr<IUndoableCommand>;