#pragma once

#include <iostream>
#include <string>
#include "UserDefineType.h"

using namespace std;

class Server
{
public:
	Server() {};
	virtual ~Server() = default;

	virtual void sendToServer(FinalResult finalResult);
	
private:

};

