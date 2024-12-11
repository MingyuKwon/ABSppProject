#pragma once

#include "BallInputInterface.h"
#include "IBallInputInterface.h"

class BallInputInterfaceAdapter : public BallInputInterface, public IBallInputInterface {
public:

    virtual ~BallInputInterfaceAdapter() = default;

    virtual void setBallTraceData(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& ballPositions);
};