#pragma once

#include <string>
#include <vector>
#include "UserDefineType.h"
#include "CalculationSystem.h"
#include "BatTraceCalcCommand.h"
#include "MessageQueue.h"

class BatInputInterface {
public:

    BatInputInterface(CalculationSystem* calculationSystem) : calculationSystem(calculationSystem) {}
    virtual ~BatInputInterface() = default;

    virtual void setBatTraceData_Origin(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& batStartPositions, const std::vector<Vector3>& batEndPositions);

private:
    CalculationSystem* calculationSystem;
    IMessageQueue* messageQueue = nullptr;
};