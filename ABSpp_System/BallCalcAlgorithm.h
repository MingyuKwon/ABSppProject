#pragma once

#include "IBallCalcAlgorithm.h"

class BallCalcAlgorithm : public IBallCalcAlgorithm
{
public:
	BallCalcAlgorithm() = default;
	virtual ~BallCalcAlgorithm() = default;

	virtual EResult calculate() const override;
	virtual void setValue(const std::vector<Vector3> ballPositions, const float& StrikeZonewidth, const float& StrikeZoneheight) override;

protected:

};