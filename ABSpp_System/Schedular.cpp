#include "Schedular.h"
#include <iostream>

Schedular::Schedular()
{
    messageQueue = MessageQueue::getInstance();
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

void Schedular::TurnOnOffScheduler(bool turnOn)
{
    stopThread = !turnOn;

    if (!stopThread)
    {
        getCommandThread = std::thread([this]() {

            while (!stopThread)
            {
                addToQueue();
                //std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }

            });

        commandExecuteThread = std::thread([this]() {

            while (!stopThread)
            {
                executeCommand();
                //std::this_thread::sleep_for(std::chrono::milliseconds(10));

            }

            });
    }
    else
    {
        if (getCommandThread.joinable())
        {
            getCommandThread.join();
        }

        if (commandExecuteThread.joinable())
        {
            commandExecuteThread.join();
        }
    }
}

void Schedular::executeCommand()
{
    if (PQ.empty()) return;

    std::lock_guard<std::mutex> lock(mtx);
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

        PQ.push(cmd);
    }
}

