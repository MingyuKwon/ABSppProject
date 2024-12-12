#pragma once

#include "UserDefineType.h"
#include "DataSaveSystem.h"
#include "Server.h"

class TotalCheck
{

public:
	TotalCheck(DataSaveSystem* dataSaveSystem, Server* server) : dataSaveSystem(dataSaveSystem), server(server){}

	void getBallStrike(int PitchCount);

private:
	DataSaveSystem* dataSaveSystem = nullptr;
	Server* server = nullptr;
};