#include "MessageQueue.h"
#include <iostream>

MessageQueue* MessageQueue::instance = nullptr;

void MessageQueue::pushCommand(AbstractCommand* command)
{
	if (command == nullptr)
	{
		std::cout << "�޽��� ť�� ���� Command�� null �Դϴ�" << std::endl;
		return;
	}
		
	if (!bActive) 
	{
		std::cout << "�޽��� ť�� non Active���� Command�� ���� �� �����ϴ�" << std::endl;
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
