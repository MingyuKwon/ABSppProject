#pragma once

#include <queue>
#include <mutex>
#include <memory>
#include "IMessageQueue.h"

class MessageQueue : public IMessageQueue {
public:
    static MessageQueue* getInstance() {
        if (instance == nullptr) {
            instance = new MessageQueue();
        }

        return instance;
    }


    virtual void pushCommand(AbstractCommand* command) override;
    virtual AbstractCommand* getCommand() override;
    virtual void setCommandAvailable(bool flag) override;

private:
    MessageQueue() = default;
    ~MessageQueue() = default;

    MessageQueue(const MessageQueue&) = delete;
    MessageQueue& operator=(const MessageQueue&) = delete;

    static MessageQueue* instance;
    std::mutex mtx;

protected:
    std::queue<AbstractCommand*> messageQueue;
    bool bActive = true;
};



