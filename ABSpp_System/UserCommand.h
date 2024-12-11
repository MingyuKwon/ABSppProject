#pragma once
#include "abstractCommand.h"

class UserCommand : public AbstractCommand
{
public:
	~UserCommand() = default;
	UserCommand() { prioirty = 1; }
};