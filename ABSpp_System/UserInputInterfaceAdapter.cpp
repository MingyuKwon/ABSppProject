#include "UserInputInterfaceAdapter.h"

void UserInputInterfaceAdapter::turnOn() const
{
	turnOn_Origin();
}

void UserInputInterfaceAdapter::turnOff() const
{
	turnOff_Origin();
}

void UserInputInterfaceAdapter::getBallStrike(int PitchCount) const
{
	getBallStrike_Origin(PitchCount);
}

void UserInputInterfaceAdapter::setBatterData(const string& batterName, const float& batterHeight)
{
	setBatterData_Origin(batterName, batterHeight);
}
