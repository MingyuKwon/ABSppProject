#include "TotalCheck.h"

void TotalCheck::getBallStrike(int PitchCount)
{
	if (server == nullptr) return;
	if (dataSaveSystem == nullptr) return;

	std::string batterName1 = "";
	std::string batterName2 = "";

	EResult ballTraceResult = ER_Failed;
	EResult batTraceResult = ER_Failed;

	EResult totalResult = ER_Failed;

	auto ballTraceResultPair = dataSaveSystem->get_ballTraceResult(PitchCount);
	auto batTraceResultPair = dataSaveSystem->get_batTraceResult(PitchCount);

	batterName1 = ballTraceResultPair.first;
	batterName2 = batTraceResultPair.first;

	if (batterName1 == "")
	{
		batterName1 = batterName2;
	}

	ballTraceResult = ballTraceResultPair.second;
	batTraceResult = batTraceResultPair.second;

	if (batterName1 == "" || batterName1 != batterName2)
	{
		batterName1 = "Error Value";
	}

	server->sendToServer(FinalResult(PitchCount, batterName1, totalResult, ballTraceResult, batTraceResult));
}
