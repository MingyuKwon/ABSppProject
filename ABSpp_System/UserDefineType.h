#pragma once
#include <utility>
#include <string>

struct Vector3
{
	float x = 0;
	float y = 0;
	float z = 0;

	Vector3() = default;
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};

struct FinalResult
{
	int pitchCount = 0;
	std::string batterName = nullptr;
	EResult TotalResult = EResult::ER_Failed;
	EResult BallTraceResult = EResult::ER_Failed;
	EResult BatTraceResult = EResult::ER_Failed;

	FinalResult() = default;
	FinalResult(int pitchCount, std::string batterName, EResult TotalResult, EResult BallTraceResult, EResult BatTraceResult) 
		: pitchCount(pitchCount), batterName(batterName), TotalResult(TotalResult), BallTraceResult(BallTraceResult), BatTraceResult(BatTraceResult) {}
};

enum EResult
{
	ER_Failed,
	ER_Strike,
	ER_Ball,
};