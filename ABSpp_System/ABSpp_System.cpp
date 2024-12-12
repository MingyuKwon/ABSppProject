#include <iostream>
#include <fstream>
#include <sstream>


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
#include "Server.h"

#include "turnOnOffCommand.h"
#include "GetBallStrikeCommand.h"

void getBallTestData(std::vector<Vector3>& ballTestData)
{
    std::ifstream file("TestDataBall.txt"); 
    if (!file.is_open())
    {
        std::cerr << "Failed to open TestDataBall.txt" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        char ignore;
        float x, y, z;

        if (iss >> ignore >> x >> ignore >> y >> ignore >> z >> ignore)
        {
            ballTestData.emplace_back(x, y, z);
        }
    }

    file.close();

}

void getBatTestData(std::vector<Vector3>& batEnd, std::vector<Vector3>& batStart)
{
    std::ifstream file("TestDataBat.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open TestDataBat.txt" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string dummy;
        char ignore;
        float x1, y1, z1, x2, y2, z2;

        if (iss >> dummy >> ignore >> x1 >> ignore >> y1 >> ignore >> z1 >> ignore >> ignore
            >> ignore >> x2 >> ignore >> y2 >> ignore >> z2 >> ignore)
        {
            batEnd.emplace_back(x1, y1, z1);
            batStart.emplace_back(x2, y2, z2);
        }
        else
        {
            std::cerr << "Failed to parse line: " << line << std::endl;
        }
    }

    file.close();
}



int main()
{
    DataSaveSystem* dataSaveModule = new DataSaveSystem();
    CalculationSystem* calculationModule = new CalculationSystem(dataSaveModule, new BallCalcAlgorithm(), new BatCalcAlgorithm());
    Server* serverModule = new Server();
    TotalCheck* totalModule = new TotalCheck(dataSaveModule, serverModule);

    IUserInputInterface* userInputModule = new UserInputInterfaceAdapter(calculationModule, totalModule);
    IBallInputInterface* ballInputModule = new BallInputInterfaceAdapter(calculationModule);
    IBatInputInterface* batInputModule = new BatInputInterfaceAdapter(calculationModule);

    IMessageQueue* messageQueue = MessageQueue::getInstance();

    
    Schedular* schedular = new Schedular();


    // 이부분을 테스트 할 때 써주시면 됩니다 아니면 여기서 쓰레드를 재생 시킨다던가 
    userInputModule->setBatterData(std::string("Batter1"), 180);

    std::vector<Vector3> ballTestData;
    getBallTestData(ballTestData);
    ballInputModule->setBallTraceData(1, std::string("Batter1"), ballTestData);

    std::vector<Vector3> batEndData;
    std::vector<Vector3> batStartData;
    getBatTestData(batEndData, batStartData);
    batInputModule->setBatTraceData(1, std::string("Batter1"), batStartData, batEndData);

    userInputModule->getBallStrike(1);
    // 이부분을 테스트 할 때 써주시면 됩니다

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    delete userInputModule;
    delete ballInputModule;
    delete batInputModule;

    delete messageQueue;

    delete calculationModule;
    delete dataSaveModule;
    delete totalModule;
    delete serverModule;
    delete schedular;

    return 0;
}

