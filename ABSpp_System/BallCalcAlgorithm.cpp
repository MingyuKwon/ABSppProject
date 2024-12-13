#include "BallCalcAlgorithm.h"
#include <iostream>

std::pair<float, float> BallCalcAlgorithm::predictXZAtYZero() const {
    if (ballPositions.size() < 2) return { 0, 0 };

    auto it = std::adjacent_find(ballPositions.begin(), ballPositions.end(),
        [](const Vector3& a, const Vector3& b) {
            return (a.y <= 0 && b.y >= 0) || (a.y >= 0 && b.y <= 0);
        });

    if (it == ballPositions.end()) return { 0, 0 }; 

    const Vector3& p1 = *it;
    const Vector3& p2 = *(it + 1);

    float t = -p1.y / (p2.y - p1.y); 
    float xAtYZero = p1.x + t * (p2.x - p1.x);
    float zAtYZero = p1.z + t * (p2.z - p1.z);

    return { xAtYZero, zAtYZero };
}

EResult BallCalcAlgorithm::calculate() const {
    bool bCanCalculate = ballPositions.size() > 0 && StrikeZonewidth > 0 && StrikeZoneheight > 0;
    if (!bCanCalculate) return EResult::ER_Failed;

    float strikeZoneLeft = -StrikeZonewidth / 2 - 1;
    float strikeZoneRight = StrikeZonewidth / 2 + 1;
    float strikeZoneBottom = 45 - 1;
    float strikeZoneTop = StrikeZoneheight + 45 + 1;


    auto result = predictXZAtYZero();
    float xAtYZero = result.first;
    float zAtYZero = result.second;

    bool inStrikeZone = (xAtYZero >= strikeZoneLeft && xAtYZero <= strikeZoneRight &&
        zAtYZero >= strikeZoneBottom && zAtYZero <= strikeZoneTop);

    std::cout << "Strike Zone: Left = " << strikeZoneLeft << ", Right = " << strikeZoneRight
        << ", Bottom = " << strikeZoneBottom << ", Top = " << strikeZoneTop << std::endl;

    std::cout << "Ball Position at Y=0: X = " << xAtYZero << ", Z = " << zAtYZero << std::endl;


    return inStrikeZone ? EResult::ER_Strike : EResult::ER_Ball;
}

void BallCalcAlgorithm::setValue(const std::vector<Vector3> ballPositions, const float& StrikeZonewidth, const float& StrikeZoneheight)
{
	this->ballPositions = ballPositions;
	this->StrikeZonewidth = StrikeZonewidth;
	this->StrikeZoneheight = StrikeZoneheight;
}
