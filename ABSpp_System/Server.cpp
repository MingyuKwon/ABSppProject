#include "Server.h"

void Server::sendToServer(FinalResult finalResult)
{
	string BallTraceResult = "Trace Fail";
	string BatTraceResult = "Trace Fail";
	string TotalResult = "Trace Fail";

	switch (finalResult.TotalResult)
	{
	case ER_Ball:
		TotalResult = "Ball";
		break;

	case ER_Strike:
		TotalResult = "Strike";
		break;
	}

	switch (finalResult.BallTraceResult)
	{
	case ER_Ball:
		BallTraceResult = "Ball";
		break;

	case ER_Strike:
		BallTraceResult = "Strike";
		break;
	}

	switch (finalResult.BatTraceResult)
	{
	case ER_Ball:
		BatTraceResult = "Not Bat Swing";
		break;

	case ER_Strike:
		BatTraceResult = "Bat Swing";
		break;
	}

	std::cout << "  ====== PitchCount : " << finalResult.pitchCount << "  " << finalResult.batterName << " =======    //Total : " << TotalResult << "//  /Ball Trace : " << BallTraceResult << "/  /Bat Trace : " << BatTraceResult << "/" << std::endl;

}
