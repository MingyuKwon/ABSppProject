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


// 이 부분 여러 데이터 반복적으로 가져오도록 고치시면 될 것 같습니다

void TestBallTraceInputThread(IBallInputInterface* ballInputModule) {
    std::ifstream file("TestDataBall.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open TestDataBall.txt" << std::endl;
        return;
    }

    std::string line;

    while (true) {
        int pitchCount = 0;
        std::string batterName;
        std::vector<Vector3> ballTestData;

        if (!std::getline(file, line)) break;
        std::istringstream iss(line);
        if (!(iss >> pitchCount)) {
            std::cerr << "Failed to parse pitch count." << std::endl;
            return;
        }

        if (!std::getline(file, line)) break;
        batterName = line;

        while (std::getline(file, line) && !line.empty()) {
            std::istringstream iss(line);
            char ignore;
            float x, y, z;

            if (iss >> ignore >> x >> ignore >> y >> ignore >> z >> ignore) {
                ballTestData.emplace_back(x, y, z);
            }
            else {
                std::cerr << "Failed to parse ball trace data." << std::endl;
            }
        }

        ballInputModule->setBallTraceData(pitchCount, batterName, ballTestData);

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    file.close();
}


void TestBatTraceInputThread(IBatInputInterface* batInputModule)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 먼저 배터 데이터가 들어간 후에 데이터를 넣어주기 위함
    std::vector<Vector3> batEndData;
    std::vector<Vector3> batStartData;
    getBatTestData(batEndData, batStartData);
    batInputModule->setBatTraceData(1, std::string("Batter1"), batStartData, batEndData);
}

void TestBatterDataInputThread(IUserInputInterface* userInputModule)
{
    std::ifstream file("TestDataInfo.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << "TestDataInfo.txt" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        float value;

        if (iss >> name >> value) {
            userInputModule->setBatterData(name, value);
        }
        else {
            std::cerr << "Failed to parse line: " << line << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    file.close();

    
}

void TestGetBSInputThread(IUserInputInterface* userInputModule)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(20)); // 먼저 다른 데이터 들을 넣은 다음에 요청을 하기 위함
    userInputModule->getBallStrike(1);
}

// 이 부분 여러 데이터 반복적으로 가져오도록 고치시면 될 것 같습니다


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
    schedular->TurnOnOffScheduler(true);

    // 테스트 쓰레드
    std::thread testBallInput(TestBallTraceInputThread, ballInputModule);
    std::thread testBatInput(TestBatTraceInputThread, batInputModule);
    std::thread testBatterDataInput(TestBatterDataInputThread, userInputModule);
    std::thread testBSInput(TestGetBSInputThread, userInputModule);
    // 테스트 쓰레드

    /// 만약 쓰레드 작업이 오래 결려서, 그 전에 main이 끝날 것 같다면 아래 숫자를 늘려서 대기하는 시간을 늘려 주세요
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    schedular->TurnOnOffScheduler(false);

    if (testBallInput.joinable()) testBallInput.join();
    if (testBatInput.joinable()) testBatInput.join();
    if (testBatterDataInput.joinable()) testBatterDataInput.join();
    if (testBSInput.joinable()) testBSInput.join();



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

