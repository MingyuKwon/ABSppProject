#pragma once

#include "UserInputInterface.h"
#include "IUserInputInterface.h"

using namespace std;

class UserInputInterfaceAdapter : public UserInputInterface, public IUserInputInterface {
public:
    virtual ~UserInputInterfaceAdapter() = default;

    virtual void turnOn() const override;

    virtual void turnOff() const override;

    virtual void getBallStrike() const override;

    virtual void setBatterData(const string& batterName, const float& batterHeight) override;

};