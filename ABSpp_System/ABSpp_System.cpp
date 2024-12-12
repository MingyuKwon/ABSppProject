#include <iostream>
#include <algorithm> 
#include <memory>
#include <chrono>
#include <thread>


#include "UserInputInterfaceAdapter.h"
#include "BallInputInterfaceAdapter.h"
#include "BatInputInterfaceAdapter.h"

#include "MessageQueue.h"

#include "BallCalcAlgorithm.h"
#include "BatCalcAlgorithm.h"


#include "TotalCheck.h"
#include "DataSaveSystem.h"
#include "CalculationSystem.h"
#include "Schedular.h"

#include "turnOnOffCommand.h"
#include "GetBallStrikeCommand.h"

int main()
{
    DataSaveSystem* dataSaveModule = new DataSaveSystem();
    CalculationSystem* calculationModule = new CalculationSystem(dataSaveModule, new BallCalcAlgorithm(), new BatCalcAlgorithm());
    TotalCheck* totalModule = new TotalCheck(dataSaveModule);

    IUserInputInterface* userInputModule = new UserInputInterfaceAdapter(calculationModule, totalModule);
    IBallInputInterface* ballInputModule = new BallInputInterfaceAdapter(calculationModule);
    IBatInputInterface* batInputModule = new BatInputInterfaceAdapter(calculationModule);

    IMessageQueue* messageQueue = MessageQueue::getInstance();

    
    
    Schedular* schedular = new Schedular();

    userInputModule->setBatterData(std::string("Batter1"), 180);
    userInputModule->getBallStrike(1);


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

