#pragma once

#include <string>
#include <vector>
#include "UserDefineType.h"



class IBallInputInterface {
public:

    virtual ~IBallInputInterface() = default;

    virtual void setBallTraceData(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& ballPositions) = 0;
};