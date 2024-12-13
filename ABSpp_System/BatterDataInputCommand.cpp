#include "BatterDataInputCommand.h"

void BatterDataInputCommand::execute()
{
	if (calculationSystem)
	{
		std::cout << " ===== CalcCommand ===== BatterDataInputCommand::execute " << std::endl;

		calculationSystem->calcStrikeZone(batterName, batterHeight);
	}
}

void BatterDataInputCommand::initCalcValue(const std::string& batterName, const float& batterHeight)
{
	this->batterName = batterName;
	this->batterHeight = batterHeight;
}
