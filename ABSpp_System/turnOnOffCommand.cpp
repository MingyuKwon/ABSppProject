#include "turnOnOffCommand.h"
#include "MessageQueue.h"


void turnOnOffCommand::execute()
{
	IMessageQueue* messageQueue = MessageQueue::getInstance();
	messageQueue->setCommandAvailable(flag);
}
