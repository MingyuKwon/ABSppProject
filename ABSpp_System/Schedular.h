#pragma once

#include "abstractCommand.h"
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>

#include "MessageQueue.h"

class CommandCompare {
public:
    bool operator()(const AbstractCommand* left, const AbstractCommand* right) const {
        return left->getPriority() < right->getPriority();
    }
};

class Schedular
{
public:
    Schedular();
    ~Schedular();

private:
    std::priority_queue<AbstractCommand*, std::vector<AbstractCommand*>, CommandCompare> PQ;
    std::thread getCommandThread;
    std::thread commandExecuteThread;

    IMessageQueue* messageQueue = nullptr;

    std::mutex mtx;

    void executeCommand();
    void addToQueue();

    bool stopThread = false;

};

