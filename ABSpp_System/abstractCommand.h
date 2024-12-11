#pragma once
#include <iostream>

class AbstractCommand
{
public:
	virtual ~AbstractCommand() = default;
	virtual void execute() = 0;
	virtual int getPriority() const { return prioirty; }

protected:
	int prioirty = 0; 
};