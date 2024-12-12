#pragma once

#include <string>

using namespace std;


class IUserInputInterface {
public:

    virtual ~IUserInputInterface() = default;

    virtual void turnOn() = 0;

    virtual void turnOff() = 0;

    virtual void getBallStrike(int PitchCount) = 0;

    virtual void setBatterData(const string& batterName, const float& batterHeight) = 0;
};