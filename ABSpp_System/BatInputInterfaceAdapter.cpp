#include "BatInputInterfaceAdapter.h"

void BatInputInterfaceAdapter::setBatTraceData(const int& PitchCount, const std::string& batterName, const std::vector<Vector3>& batStartPositions, const std::vector<Vector3>& batEndPositions)
{
	setBatTraceData_Origin(PitchCount, batterName, batStartPositions, batEndPositions);
}
