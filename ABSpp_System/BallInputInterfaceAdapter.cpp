#include "BallInputInterfaceAdapter.h"

void BallInputInterfaceAdapter::setBallTraceData(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& ballPositions)
{
	setBallTraceData_Origin(PitchCount, batterName, ballPositions);
}
