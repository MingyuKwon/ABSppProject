#include "TotalCheck.h"

void TotalCheck::getBallStrike(int PitchCount)
{
	if (server == nullptr) return;
	if (dataSaveSystem == nullptr) return;

	std::string finalName = "";
	std::string batterName1 = "";
	std::string batterName2 = "";

	EResult ballTraceResult = ER_Failed;
	EResult batTraceResult = ER_Failed;

	EResult totalResult = ER_Failed;

	auto ballTraceResultPair = dataSaveSystem->get_ballTraceResult(PitchCount);
	auto batTraceResultPair = dataSaveSystem->get_batTraceResult(PitchCount);

	batterName1 = ballTraceResultPair.first;
	batterName2 = batTraceResultPair.first;

	ballTraceResult = ballTraceResultPair.second;
	batTraceResult = batTraceResultPair.second;

	if (ballTraceResult == ER_Failed && batTraceResult == ER_Failed)
	{
		finalName = "Error Value";
	}
	else if (ballTraceResult == ER_Failed)
	{
		finalName = batterName2;
	}
	else if (batTraceResult == ER_Failed)
	{
		finalName = batterName1;
	}
	else
	{
		if (batterName1 == batterName2)
		{
			finalName = batterName1;

			if (batTraceResult == ER_Strike)
			{
				totalResult = ER_Strike;
			}
			else
			{
				if (ballTraceResult == ER_Strike)
				{
					totalResult = ER_Strike;
				}
				else
				{
					totalResult = ER_Ball;
				}
			}
		}
		else
		{
			finalName = "Error Value";
		}
	}

	server->sendToServer(FinalResult(PitchCount, finalName, totalResult, ballTraceResult, batTraceResult));
}
