#pragma once

class AbstractCommand
{
public:
	virtual ~AbstractCommand() = default;
	virtual void execute() = 0;
	virtual int getPriority() { return prioirty; }

protected:
	int prioirty = 0; 
};