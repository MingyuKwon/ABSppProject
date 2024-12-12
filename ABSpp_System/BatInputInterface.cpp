#include "BatInputInterface.h"

void BatInputInterface::setBatTraceData_Origin(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& batStartPositions, const std::vector<Vector3>& batEndPositions)
{
	if (calculationSystem == nullptr) return;

	messageQueue = (messageQueue == nullptr) ? MessageQueue::getInstance() : messageQueue;
	if (messageQueue == nullptr) return;

	BatTraceCalcCommand* cmd = new BatTraceCalcCommand(calculationSystem);
	cmd->initCalcValue(PitchCount, batterName, batStartPositions, batEndPositions);

	messageQueue->pushCommand(cmd);
}
