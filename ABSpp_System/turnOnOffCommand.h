#pragma once
#include "UserCommand.h"

class turnOnOffCommand :public UserCommand
{
public:
	turnOnOffCommand(bool flag) : flag(flag) { prioirty = 2; }
	~turnOnOffCommand() = default;

	virtual void execute() override;

private:
	bool flag = false;
};


