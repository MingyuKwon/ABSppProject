#include "Schedular.h"
#include <iostream>

Schedular::Schedular()
{
    messageQueue = MessageQueue::getInstance();

    getCommandThread = std::thread([this]() {

        while (!stopThread)
        {
            addToQueue();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        });

    commandExecuteThread = std::thread([this]() {

        while (!stopThread)
        {
            executeCommand();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            
        }

        });
}

Schedular::~Schedular()
{
    stopThread = true;

    if (getCommandThread.joinable())
    {
        getCommandThread.join();
    }

    if (commandExecuteThread.joinable())
    {
        commandExecuteThread.join();
    }
}

void Schedular::executeCommand()
{
    if (PQ.empty()) return;

    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "executeCommand\n";

    AbstractCommand* cmd = PQ.top();
    PQ.pop();

    cmd->execute();
    delete cmd;
}

void Schedular::addToQueue()
{
    if (messageQueue == nullptr) return;

    AbstractCommand* cmd = messageQueue->getCommand();
    if (cmd)
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "addToQueue\n";

        PQ.push(cmd);
    }
}

