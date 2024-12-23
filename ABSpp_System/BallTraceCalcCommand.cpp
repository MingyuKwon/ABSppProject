#include "BallTraceCalcCommand.h"

void BallTraceCalcCommand::execute()
{
	if (calculationSystem)
	{
		std::cout << " ===== CalcCommand ===== BallTraceCalcCommand::execute \n";

		calculationSystem->calcBallTrace(pitchCount, batterName, ballPositions);
	}
}

void BallTraceCalcCommand::initCalcValue(const int& pitchCount, const std::string& batterName, const std::vector<Vector3> ballPositions)
{
	this->pitchCount = pitchCount;
	this->batterName = batterName;
	this->ballPositions = ballPositions;
}
