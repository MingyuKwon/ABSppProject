#pragma once

#include "UserDefineType.h"
#include <string>
#include <unordered_map>

using namespace std;

class DataSaveSystem
{
public:
	DataSaveSystem() = default;
	virtual ~DataSaveSystem() = default;

	void save_ballTraceResult(const int& pitchCount, const string& batterName, const EResult& result);
	void save_batTraceResult(const int& pitchCount, const string& batterName, const EResult& result);
	void save_batterData(const string& batterName, const float& width, const float& height);

	pair<string, EResult> get_ballTraceResult(int pitchCount);
	pair<string, EResult> get_batTraceResult(int pitchCount);
	void get_batterData(const string& batterName, float& width, float& height);

private:
	unordered_map<int, pair<string, EResult> > ballTraceResultHash;
	unordered_map<int, pair<string, EResult>> batTraceResultHash;
	unordered_map<string, pair<float, float>> batterDataHash;


};

