#pragma once

#include <string>
#include <vector>
#include "UserDefineType.h"


class BatInputInterface {
public:

    virtual ~BatInputInterface() = default;

    virtual void setBatTraceData_Origin(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& batStartPositions, const std::vector<Vector3>& batEndPositions);
};