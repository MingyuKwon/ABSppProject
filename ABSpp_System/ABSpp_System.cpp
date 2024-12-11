#include <iostream>
#include <algorithm> 
#include <memory>
#include <chrono>
#include <thread>


#include "UserInputInterfaceAdapter.h"
#include "BallInputInterfaceAdapter.h"
#include "BatInputInterfaceAdapter.h"

#include "MessageQueue.h"

#include "TotalCheck.h"
#include "DataSaveSystem.h"
#include "Schedular.h"

#include "turnOnOffCommand.h"
#include "GetBallStrikeCommand.h"

int main()
{
    IUserInputInterface* userInputModule = new UserInputInterfaceAdapter();
    IBallInputInterface* ballInputModule = new BallInputInterfaceAdapter();
    IBatInputInterface* batInputModule = new BatInputInterfaceAdapter();

    IMessageQueue* messageQueue = MessageQueue::getInstance();

    DataSaveSystem* dataSaveModule = new DataSaveSystem();
    TotalCheck* totalModule = new TotalCheck(dataSaveModule);
    Schedular* schedular = new Schedular();


    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    
    std::cout << " " << std::endl;

    delete userInputModule;
    delete ballInputModule;
    delete batInputModule;

    delete messageQueue;

    delete dataSaveModule;
    delete totalModule;

    return 0;
}

