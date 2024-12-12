#include "UserInputInterfaceAdapter.h"

void UserInputInterfaceAdapter::turnOn()
{
	turnOn_Origin();
}

void UserInputInterfaceAdapter::turnOff()
{
	turnOff_Origin();
}

void UserInputInterfaceAdapter::getBallStrike(int PitchCount) 
{
	getBallStrike_Origin(PitchCount);
}

void UserInputInterfaceAdapter::setBatterData(const string& batterName, const float& batterHeight)
{
	setBatterData_Origin(batterName, batterHeight);
}
