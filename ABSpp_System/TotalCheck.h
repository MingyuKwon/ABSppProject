#pragma once

#include "DataSaveSystem.h"

class TotalCheck
{

public:
	TotalCheck(DataSaveSystem* dataSaveSystem) : dataSaveSystem(dataSaveSystem) {}

	void getBallStrike(int PitchCount);

private:
	DataSaveSystem* dataSaveSystem;

};