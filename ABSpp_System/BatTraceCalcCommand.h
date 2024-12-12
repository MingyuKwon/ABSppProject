#pragma once


#include "CalcCommand.h"
#include "CalculationSystem.h"

class BatTraceCalcCommand : public CalcCommand
{
public:
	BatTraceCalcCommand(CalculationSystem* calculationSystem) : calculationSystem(calculationSystem) {}
	virtual	~BatTraceCalcCommand() = default;

	virtual void execute() override;
	virtual void initCalcValue(const int& pitchCount, const std::string& batterName, const std::vector<Vector3> batStartPositions, const std::vector<Vector3> batEndPositions);

private:
	CalculationSystem* calculationSystem;
	std::vector<Vector3> batStartPositions;
	std::vector<Vector3> batEndPositions;
	std::string batterName;
	int pitchCount = 0;
};