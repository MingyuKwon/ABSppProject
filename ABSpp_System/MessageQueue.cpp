#include "MessageQueue.h"
#include <iostream>

MessageQueue* MessageQueue::instance = nullptr;

void MessageQueue::pushCommand(AbstractCommand* command)
{
	if (command == nullptr)
	{
		std::cout << "메시지 큐에 들어온 Command가 null 입니다" << std::endl;
		return;
	}
		
	if (!bActive) 
	{
		std::cout << "메시지 큐가 non Active여서 Command를 받을 수 없습니다" << std::endl;
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

	std::cout << messageQueue.size() << std::endl;

	return popCommand;
}

void MessageQueue::setCommandAvailable(bool flag)
{
	bActive = flag;
}
