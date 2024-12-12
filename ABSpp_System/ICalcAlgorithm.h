#pragma once
#include "UserDefineType.h"
#include <string>
#include <vector>

class ICalcAlgorithm
{
public:
	ICalcAlgorithm() = default;
	virtual ~ICalcAlgorithm() = default;

	virtual EResult calculate() const  = 0;

private:

};
