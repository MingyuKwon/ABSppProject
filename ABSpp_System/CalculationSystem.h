#pragma once
#include "DataSaveSystem.h"
#include "IBatCalcAlgorithm.h"
#include "IBallCalcAlgorithm.h"

class CalculationSystem
{
public:
	CalculationSystem(DataSaveSystem* dataSaveSystem , IBallCalcAlgorithm* ballCalcAlgorithm, IBatCalcAlgorithm* batCalcAlgorithm)
		: dataSaveSystem(dataSaveSystem), batCalcAlgorithm(batCalcAlgorithm), ballCalcAlgorithm(ballCalcAlgorithm) { }

	virtual ~CalculationSystem() {
		delete batCalcAlgorithm;
		delete ballCalcAlgorithm;
	};

	void calcBallTrace(const int& pitchCount, const std::string& batterName, const std::vector<Vector3> ballPositions);
	void calcBatTrace(const int& pitchCount , const std::string& batterName, const std::vector<Vector3> batStartPositions, const std::vector<Vector3> batEndPositions);
	void calcStrikeZone(const std::string& batterName, const float& batterHeight);

private:
	DataSaveSystem* dataSaveSystem = nullptr;
	IBatCalcAlgorithm* batCalcAlgorithm = nullptr;
	IBallCalcAlgorithm* ballCalcAlgorithm = nullptr;

	float strikeZoneWidth = 47.18;
	float strikeZoneHeight[8] = { 56 , 55, 53, 52, 51, 50, 49, 47};
	int HeightZone[8] = { 195 , 190, 185, 180, 175, 170, 165, 160 };
};


