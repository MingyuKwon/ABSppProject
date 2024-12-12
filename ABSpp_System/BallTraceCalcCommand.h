#pragma once

#include "CalcCommand.h"
#include "CalculationSystem.h"

class BallTraceCalcCommand : public CalcCommand
{
public:
	BallTraceCalcCommand(CalculationSystem* calculationSystem) : calculationSystem(calculationSystem) {}
	virtual	~BallTraceCalcCommand() = default;

	virtual void execute() override;
	virtual void initCalcValue(const int& pitchCount, const std::string& batterName, const std::vector<Vector3> ballPositions);

private:
	CalculationSystem* calculationSystem;
	std::vector<Vector3> ballPositions;
	std::string batterName;
	int pitchCount = 0;
};

