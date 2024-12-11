#include "UserInputInterfaceAdapter.h"

void UserInputInterfaceAdapter::turnOn() const
{
	turnOn_Origin();
}

void UserInputInterfaceAdapter::turnOff() const
{
	turnOff_Origin();
}

void UserInputInterfaceAdapter::getBallStrike() const
{
	getBallStrike_Origin();
}

void UserInputInterfaceAdapter::setBatterData(const string& batterName, const float& batterHeight)
{
	setBatterData_Origin(batterName, batterHeight);
}
