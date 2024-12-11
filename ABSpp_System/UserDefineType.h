#pragma once
#include <utility>

struct Vector3
{
	float x = 0;
	float y = 0;
	float z = 0;

	Vector3() = default;
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};

enum EResult
{
	ER_Failed,
	ER_Strike,
	ER_Ball,
};