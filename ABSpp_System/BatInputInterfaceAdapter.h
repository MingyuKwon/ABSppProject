#pragma once
#include "BatInputInterface.h"
#include "IBatInputInterface.h"


class BatInputInterfaceAdapter : public BatInputInterface , public IBatInputInterface {
public:
    BatInputInterfaceAdapter(CalculationSystem* calculationSystem) : BatInputInterface(calculationSystem) {}

    virtual ~BatInputInterfaceAdapter() = default;

    virtual void setBatTraceData(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& batStartPositions, const std::vector<Vector3>& batEndPositions);
};
