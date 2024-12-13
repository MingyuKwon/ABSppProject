#include "BatTraceCalcCommand.h"

void BatTraceCalcCommand::execute()
{
	if (calculationSystem)
	{
		std::cout << " ===== CalcCommand ===== BatTraceCalcCommand::execute " << std::endl;

		calculationSystem->calcBatTrace(pitchCount, batterName, batStartPositions, batEndPositions);
	}
}

void BatTraceCalcCommand::initCalcValue(const int& pitchCount, const std::string& batterName, const std::vector<Vector3> batStartPositions, const std::vector<Vector3> batEndPositions)
{
	this->pitchCount = pitchCount;
	this->batterName = batterName;
	this->batStartPositions = batStartPositions;
	this->batEndPositions = batEndPositions;
}
