#include "BallCalcAlgorithm.h"

EResult BallCalcAlgorithm::calculate() const
{
	bool bCanCalculate = ballPositions.size() > 0 && StrikeZonewidth > 0 && StrikeZoneheight > 0;
	if (!bCanCalculate) return EResult::ER_Failed;


	return EResult::ER_Failed;
}

void BallCalcAlgorithm::setValue(const std::vector<Vector3> ballPositions, const float& StrikeZonewidth, const float& StrikeZoneheight)
{
	this->ballPositions = ballPositions;
	this->StrikeZonewidth = StrikeZonewidth;
	this->StrikeZoneheight = StrikeZoneheight;
}
