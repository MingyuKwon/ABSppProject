#pragma once
#include "ICalcAlgorithm.h"

class IBallCalcAlgorithm : public ICalcAlgorithm
{
public:
	IBallCalcAlgorithm() = default;
	virtual ~IBallCalcAlgorithm() = default;

	virtual EResult calculate() const override = 0;
	virtual void setValue(const std::vector<Vector3> ballPositions, const float& StrikeZonewidth, const float& StrikeZoneheight) = 0;

protected:
	std::vector<Vector3> ballPositions;
	float StrikeZonewidth = 0;
	float StrikeZoneheight = 0;

};


