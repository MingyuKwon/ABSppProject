#pragma once

#include <string>

using namespace std;

class UserInputInterface {
public:
    virtual ~UserInputInterface() = default;

    virtual void turnOn_Origin() const;

    virtual void turnOff_Origin() const;

    virtual void getBallStrike_Origin() const;

    virtual void setBatterData_Origin(const string& batterName, const float& batterHeight);
};
