#include "BatCalcAlgorithm.h"

EResult BatCalcAlgorithm::calculate() const
{
    bool bCanCalculate = batStartPositions.size() > 0 && batEndPositions.size() > 0;
    if (!bCanCalculate) return EResult::ER_Failed;

    // first check batend is out of the foul line
    bool bBatEndOutOfLine = false;

    auto isBetweenFoulLines = [](const Vector3& pos) -> bool {
        return (pos.x <= pos.y) && (pos.x >= -pos.y);
        };

    for (const auto& pos : batEndPositions) {
        if (isBetweenFoulLines(pos)) {
            bBatEndOutOfLine = true;
            break;
        }
    }

    if (!bBatEndOutOfLine)
    {
        return EResult::ER_Ball;
    }
    
    Vector3 initialStart = batStartPositions[0];
    Vector3 initialEnd = batEndPositions[0];
    Vector3 initialVector = initialEnd - initialStart;

    float initialMagnitude = initialVector.magnitude();
    if (initialMagnitude == 0) {
        std::cerr << "Invalid initial vector magnitude.\n";
        return EResult::ER_Failed;
    }

    float maxAngle = 0.0f;

    for (size_t i = 1; i < batStartPositions.size() && i < batEndPositions.size(); ++i) {
        Vector3 currentStart = batStartPositions[i];
        Vector3 currentEnd = batEndPositions[i];
        Vector3 currentVector = currentEnd - currentStart;

        float currentMagnitude = currentVector.magnitude();
        if (currentMagnitude == 0) continue; 

        float dotProduct = initialVector.dot(currentVector);
        float cosTheta = dotProduct / (initialMagnitude * currentMagnitude);
        cosTheta = std::max(-1.0f, std::min(1.0f, cosTheta)); 
        float angle = std::acos(cosTheta) * (180.0f / 3.14f); 

        maxAngle = std::max(maxAngle, angle);
    }

    std::cout << "&&&&&&& Max Angle: " << maxAngle << " degrees\n";
    std::cout << (maxAngle >= 40.f ? "&&&&&&& Max Angle exceeds 40 degrees.\n" : "Max Angle is below 40 degrees.\n");


    if (maxAngle >= 40.f) {
        return EResult::ER_Strike;
    }
    else {
        return EResult::ER_Ball;
    }
    

    
}

void BatCalcAlgorithm::setValue(const std::vector<Vector3> batStartPositions, const std::vector<Vector3> batEndPositions)
{
    this->batStartPositions = batStartPositions;
    this->batEndPositions = batEndPositions;
}
