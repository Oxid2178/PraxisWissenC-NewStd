#pragma once

class IHund {
public:
	virtual void spielen() = 0;
	virtual void essen() = 0;

	virtual ~IHund() = default;
};