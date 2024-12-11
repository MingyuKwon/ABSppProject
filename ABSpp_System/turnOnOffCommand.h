#pragma once
#include "UserCommand.h"

class turnOnOffCommand :public UserCommand
{
public:
	turnOnOffCommand(bool flag);
	~turnOnOffCommand() = default;

	virtual void execute() override;

private:

};


