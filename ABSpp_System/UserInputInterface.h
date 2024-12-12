#pragma once

#include <string>
#include "CalculationSystem.h"
#include "TotalCheck.h"
#include "BatterDataInputCommand.h"
#include "GetBallStrikeCommand.h"
#include "turnOnOffCommand.h"
#include "MessageQueue.h"

using namespace std;

class UserInputInterface {
public:
    UserInputInterface(CalculationSystem* calculationSystem, TotalCheck* totalCheck) : calculationSystem(calculationSystem), totalCheck(totalCheck){}

    virtual ~UserInputInterface() = default;

    virtual void turnOn_Origin();

    virtual void turnOff_Origin();

    virtual void getBallStrike_Origin(int PitchCount);

    virtual void setBatterData_Origin(const string& batterName, const float& batterHeight);

private:
    CalculationSystem* calculationSystem = nullptr;
    TotalCheck* totalCheck = nullptr;
    IMessageQueue* messageQueue = nullptr;

};
