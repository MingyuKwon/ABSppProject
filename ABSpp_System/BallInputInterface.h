#pragma once
#include <string>
#include <vector>
#include "UserDefineType.h"


class BallInputInterface {
public:

    virtual ~BallInputInterface() = default;

    virtual void setBallTraceData_Origin(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& ballPositions);
};