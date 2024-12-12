#include "UserInputInterface.h"

void UserInputInterface::turnOn_Origin()
{
	messageQueue = (messageQueue == nullptr) ? MessageQueue::getInstance() : messageQueue;
	if (messageQueue == nullptr) return;

	turnOnOffCommand* cmd = new turnOnOffCommand(true);

	messageQueue->pushCommand(cmd);

	
}

void UserInputInterface::turnOff_Origin()
{
	messageQueue = (messageQueue == nullptr) ? MessageQueue::getInstance() : messageQueue;
	if (messageQueue == nullptr) return;

	turnOnOffCommand* cmd = new turnOnOffCommand(false);

	messageQueue->pushCommand(cmd);
}

void UserInputInterface::getBallStrike_Origin(int PitchCount) 
{
	if (totalCheck == nullptr) return;

	messageQueue = (messageQueue == nullptr) ? MessageQueue::getInstance() : messageQueue;
	if (messageQueue == nullptr) return;

	GetBallStrikeCommand* cmd = new GetBallStrikeCommand(totalCheck, PitchCount);

	messageQueue->pushCommand(cmd);

}

void UserInputInterface::setBatterData_Origin(const string& batterName, const float& batterHeight)
{
	if (calculationSystem == nullptr) return;

	messageQueue = (messageQueue == nullptr) ? MessageQueue::getInstance() : messageQueue;
	if (messageQueue == nullptr) return;

	BatterDataInputCommand* cmd = new BatterDataInputCommand(calculationSystem);
	cmd->initCalcValue(batterName, batterHeight);

	messageQueue->pushCommand(cmd);
}
