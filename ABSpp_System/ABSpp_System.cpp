#include <iostream>
#include <algorithm> 
#include <memory>

#include "UserInputInterfaceAdapter.h"
#include "BallInputInterfaceAdapter.h"
#include "BatInputInterfaceAdapter.h"

#include "MessageQueue.h"

#include "TotalCheck.h"

#include "turnOnOffCommand.h"

int main()
{
    std::unique_ptr<IUserInputInterface> userInputModule = std::make_unique<UserInputInterfaceAdapter>();
    std::unique_ptr<IBallInputInterface> ballInputModule = std::make_unique<BallInputInterfaceAdapter>();
    std::unique_ptr<IBatInputInterface> batInputModule = std::make_unique<BatInputInterfaceAdapter>();

    IMessageQueue* messageQueue = MessageQueue::getInstance();
    messageQueue->pushCommand(new turnOnOffCommand(false));
    messageQueue->getCommand();

    
    std::cout << " " << std::endl;

    delete messageQueue;

    return 0;
}

