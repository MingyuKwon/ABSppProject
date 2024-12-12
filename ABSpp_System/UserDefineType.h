#pragma once
#include <utility>
#include <string>
#include <cmath>

struct Vector3
{
	float x = 0;
	float y = 0;
	float z = 0;

	Vector3() = default;
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	Vector3 operator-(const Vector3& other) const {
		return { x - other.x, y - other.y, z - other.z };
	}

	float magnitude() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	float dot(const Vector3& other) const {
		return x * other.x + y * other.y + z * other.z;
	}
};

enum EResult
{
	ER_Failed,
	ER_Strike,
	ER_Ball,
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

