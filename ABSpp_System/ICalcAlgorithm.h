#pragma once
#include "UserDefineType.h"
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <iostream>
#include <algorithm>


class ICalcAlgorithm
{
public:
	ICalcAlgorithm() = default;
	virtual ~ICalcAlgorithm() = default;

	virtual EResult calculate() const  = 0;

private:

};
