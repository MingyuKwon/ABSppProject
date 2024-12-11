#pragma once

#include "abstractCommand.h"


class IMessageQueue 
{
public:
	virtual ~IMessageQueue() = default;

	virtual void pushCommand(AbstractCommand* command) = 0;
	virtual AbstractCommand* getCommand() = 0;
	virtual void setCommandAvailable(bool flag) = 0;

};