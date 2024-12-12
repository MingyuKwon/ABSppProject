#pragma once
#include "DataSaveSystem.h"
#include "IBatCalcAlgorithm.h"
#include "IBallCalcAlgorithm.h"

class CalculationSystem
{
public:
	CalculationSystem(DataSaveSystem* dataSaveSystem, IBatCalcAlgorithm* batCalcAlgorithm , IBallCalcAlgorithm* ballCalcAlgorithm) 
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

};


