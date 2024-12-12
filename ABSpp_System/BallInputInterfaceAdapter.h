#pragma once

#include "BallInputInterface.h"
#include "IBallInputInterface.h"

class BallInputInterfaceAdapter : public BallInputInterface, public IBallInputInterface {
public:
    BallInputInterfaceAdapter(CalculationSystem* calculationSystem) : BallInputInterface(calculationSystem) {}

    virtual ~BallInputInterfaceAdapter() = default;

    virtual void setBallTraceData(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& ballPositions);
};