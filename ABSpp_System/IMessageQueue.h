#pragma once

#include <queue>
#include <mutex>

class IMessageQueue 
{
public:
	virtual ~IMessageQueue() = default;

	virtual void pushCommand() = 0;
	virtual void getCommand() = 0;
	virtual void setCommandAvailable(bool flag) = 0;

};