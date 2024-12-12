#pragma once
#include "ICalcAlgorithm.h"

class IBatCalcAlgorithm : public ICalcAlgorithm
{
public:
	IBatCalcAlgorithm() = default;
	virtual ~IBatCalcAlgorithm() = default;

	virtual EResult calculate() const override = 0;
	virtual void setValue(const std::vector<Vector3> batStartPositions, const std::vector<Vector3> batEndPositions) = 0;

protected:
	std::vector<Vector3> batStartPositions;
	std::vector<Vector3> batEndPositions;
};