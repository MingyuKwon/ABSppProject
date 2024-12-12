#pragma once
#include <string>
#include <vector>
#include "UserDefineType.h"
#include "CalculationSystem.h"
#include "BallTraceCalcCommand.h"
#include "MessageQueue.h"


class BallInputInterface {
public:

    BallInputInterface(CalculationSystem* calculationSystem) : calculationSystem(calculationSystem) {}
    virtual ~BallInputInterface() = default;

    virtual void setBallTraceData_Origin(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& ballPositions);

private:
    CalculationSystem* calculationSystem;
    IMessageQueue* messageQueue = nullptr;
};