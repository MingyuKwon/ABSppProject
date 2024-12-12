#include "BallInputInterface.h"

void BallInputInterface::setBallTraceData_Origin(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& ballPositions)
{
	if (calculationSystem == nullptr) return;

	messageQueue = (messageQueue == nullptr) ? MessageQueue::getInstance() : messageQueue;
	if (messageQueue == nullptr) return;

	BallTraceCalcCommand* cmd = new BallTraceCalcCommand(calculationSystem);
	cmd->initCalcValue(PitchCount, batterName, ballPositions);

	messageQueue->pushCommand(cmd);
}
