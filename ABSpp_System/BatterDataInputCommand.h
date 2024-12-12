#pragma once
#include "CalcCommand.h"
#include "CalculationSystem.h"

class BatterDataInputCommand : public CalcCommand
{
public:
	BatterDataInputCommand(CalculationSystem* calculationSystem) : calculationSystem(calculationSystem) {}
	virtual	~BatterDataInputCommand() = default;

	virtual void execute() override;
	virtual void initCalcValue(const std::string& batterName, const float& batterHeight);

private:
	CalculationSystem* calculationSystem;
	std::string batterName;
	float batterHeight = 0;
};

