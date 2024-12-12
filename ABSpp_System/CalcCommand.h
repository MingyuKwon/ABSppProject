#pragma once
#include "abstractCommand.h"

class CalcCommand : public AbstractCommand
{
public:
	~CalcCommand() = default;
	CalcCommand() { prioirty = 0; }

private:

};




