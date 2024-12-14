#pragma once

#include "UserInputInterface.h"
#include "IUserInputInterface.h"

using namespace std;

class UserInputInterfaceAdapter : public UserInputInterface, public IUserInputInterface {
public:

    UserInputInterfaceAdapter(CalculationSystem* calculationSystem, TotalCheck* totalCheck) 
        : UserInputInterface(calculationSystem, totalCheck) {}

    virtual ~UserInputInterfaceAdapter() = default;

    virtual void turnOn() override;

    virtual void turnOff() override;

    virtual void getBallStrike(int PitchCount) override;

    virtual void setBatterData(const string& batterName, const float& batterHeight) override;

};