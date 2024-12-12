#include "BatCalcAlgorithm.h"

EResult BatCalcAlgorithm::calculate() const
{
    bool bCanCalculate = batStartPositions.size() > 0 && batEndPositions.size() > 0;
    if (!bCanCalculate) return EResult::ER_Failed;

    return EResult::ER_Failed;
}

void BatCalcAlgorithm::setValue(const std::vector<Vector3> batStartPositions, const std::vector<Vector3> batEndPositions)
{
    this->batStartPositions = batStartPositions;
    this->batEndPositions = batEndPositions;
}
