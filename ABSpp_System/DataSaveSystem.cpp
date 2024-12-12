#include "DataSaveSystem.h"
#include <iostream>

void DataSaveSystem::save_ballTraceResult(const int& pitchCount, const string& batterName, const EResult& result)
{
	if (pitchCount < 1) return;
	if (batterName.empty()) return;

	ballTraceResultHash.insert({ pitchCount, { batterName , result } });
}

void DataSaveSystem::save_batTraceResult(const int& pitchCount, const string& batterName, const EResult& result)
{
	if (pitchCount < 1) return;
	if (batterName.empty()) return;


	batTraceResultHash.insert({ pitchCount, { batterName , result } });
}

void DataSaveSystem::save_batterData(const string& batterName, const float& width, const float& height)
{
	if (batterName.empty()) return;

	batterDataHash.insert({ batterName , {width, height } });
}

pair<string, EResult> DataSaveSystem::get_ballTraceResult(int pitchCount)
{
	if (pitchCount < 1) return {"", ER_Failed };

	if (ballTraceResultHash.find(pitchCount) != ballTraceResultHash.end())
	{
		return ballTraceResultHash[pitchCount];
	}

	return { "", ER_Failed };
}

pair<string, EResult> DataSaveSystem::get_batTraceResult(int pitchCount)
{
	if (pitchCount < 1) return { "", ER_Failed };

	if (batTraceResultHash.find(pitchCount) != batTraceResultHash.end())
	{
		return batTraceResultHash[pitchCount];
	}

	return { "", ER_Failed };
}

void DataSaveSystem::get_batterData(const string& batterName, float& width, float& height)
{
	if (batterDataHash.find(batterName) != batterDataHash.end())
	{
		width = batterDataHash[batterName].first;
		height = batterDataHash[batterName].second;
	}
	else
	{
		width = 0;
		height = 0;
	}
}
