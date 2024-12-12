#include "MessageQueue.h"
#include <iostream>

MessageQueue* MessageQueue::instance = nullptr;

void MessageQueue::pushCommand(AbstractCommand* command)
{
	if (command == nullptr)
	{
		std::cout << "Input command is Null" << std::endl;
		return;
	}
		
	if (!bActive && command->getPriority() == 0)
	{
		std::cout << "Message Queue is turn off and cannot get Command" << std::endl;
		return;
	}

	std::lock_guard<std::mutex> lock(mtx);

	messageQueue.push(command);

	std::cout << messageQueue.size() << std::endl;
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
