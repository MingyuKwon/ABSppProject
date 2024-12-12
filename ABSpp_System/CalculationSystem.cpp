#include "CalculationSystem.h"

void CalculationSystem::calcBallTrace(const int& pitchCount, const std::string& batterName, const std::vector<Vector3> ballPositions)
{
	if (dataSaveSystem == nullptr) return;
	if (ballCalcAlgorithm == nullptr) return;

	float width = 0;
	float height = 0;
	dataSaveSystem->get_batterData(batterName, width, height);

	if (width == 0 || height == 0) return;

	ballCalcAlgorithm->setValue(ballPositions, width, height);
	EResult result =  ballCalcAlgorithm->calculate();

	dataSaveSystem->save_ballTraceResult(pitchCount, batterName, result);
}

void CalculationSystem::calcBatTrace(const int& pitchCount, const std::string& batterName,
	const std::vector<Vector3> batStartPositions, const std::vector<Vector3> batEndPositions)
{
	if (dataSaveSystem == nullptr) return;
	if (batCalcAlgorithm == nullptr) return;

	batCalcAlgorithm->setValue(batStartPositions, batEndPositions);
	EResult result = batCalcAlgorithm->calculate();

	dataSaveSystem->save_batTraceResult(pitchCount, batterName, result);
}

void CalculationSystem::calcStrikeZone(const std::string& batterName, const float& batterHeight)
{
	if (dataSaveSystem == nullptr) return;

	int index = 0;
	for (; index < 8; index++)
	{
		if (HeightZone[index] <= batterHeight) break;
	}

	index = max(index, 7);

	dataSaveSystem->save_batterData(batterName, strikeZoneWidth, strikeZoneHeight[index]);

}
