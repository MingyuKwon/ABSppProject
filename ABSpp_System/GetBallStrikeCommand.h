#pragma once

#include "UserCommand.h"
#include "TotalCheck.h"

class GetBallStrikeCommand : public UserCommand
{
public:
	GetBallStrikeCommand(TotalCheck* totalCheck, int PitchCount) : totalCheck(totalCheck) , PitchCount(PitchCount) {};

	virtual void execute() override;


private:
	TotalCheck* totalCheck;
	int PitchCount = 0;
};

