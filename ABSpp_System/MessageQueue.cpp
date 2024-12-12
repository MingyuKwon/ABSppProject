#include "MessageQueue.h"
#include <iostream>

MessageQueue* MessageQueue::instance = nullptr;

void MessageQueue::pushCommand(AbstractCommand* command)
{
	if (command == nullptr)
	{
		std::cout << "add to Message queue Fail : Input command is Null" << std::endl;
		return;
	}
		
	if (!bActive && command->getPriority() == 0)
	{
		std::cout << "add to Message queue Fail : Message Queue is turn off and cannot get Command" << std::endl;
		return;
	}

	std::lock_guard<std::mutex> lock(mtx);

	messageQueue.push(command);

	std::cout << "add to Message queue : " << messageQueue.size() << std::endl;
}

AbstractCommand* MessageQueue::getCommand()
{
	if (messageQueue.empty())
	{
		return nullptr;
	}
	std::lock_guard<std::mutex> lock(mtx);

	AbstractCommand* popCommand = messageQueue.front();
	messageQueue.pop();

	return popCommand;
}

void MessageQueue::setCommandAvailable(bool flag)
{
	bActive = flag;
}
