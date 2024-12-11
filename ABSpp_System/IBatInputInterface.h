#pragma once
 
#include <string>
#include <vector>
#include "UserDefineType.h"

class IBatInputInterface {
public:

    virtual ~IBatInputInterface() = default;

    virtual void setBatTraceData(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& batStartPositions, const std::vector<Vector3>& batEndPositions) = 0;
};