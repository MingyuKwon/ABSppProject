#pragma once
#include "IBatCalcAlgorithm.h"

class BatCalcAlgorithm : public IBatCalcAlgorithm
{
public:
	BatCalcAlgorithm() = default;
	virtual ~BatCalcAlgorithm() = default;

	virtual EResult calculate() const override;
	virtual void setValue(const std::vector<Vector3> batStartPositions, const std::vector<Vector3> batEndPositions) override;

protected:

};