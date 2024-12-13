#include "GetBallStrikeCommand.h"

void GetBallStrikeCommand::execute()
{
	if (totalCheck && PitchCount > 0)
	{
		std::cout << " ===== UserCommand ===== GetBallStrikeCommand::execute \n";
		totalCheck->getBallStrike(PitchCount);
	}
}
