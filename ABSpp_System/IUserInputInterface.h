#pragma once

#include <string>

using namespace std;


class IUserInputInterface {
public:

    virtual ~IUserInputInterface() = default;

    virtual void turnOn() const = 0;

    virtual void turnOff() const = 0;

    virtual void getBallStrike(int PitchCount) const = 0;

    virtual void setBatterData(const string& batterName, const float& batterHeight) = 0;
};