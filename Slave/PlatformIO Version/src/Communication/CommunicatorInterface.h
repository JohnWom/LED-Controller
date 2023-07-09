//
// Created by johnw on 7/8/2023.
//

#ifndef COMMUNICATOR_INTERFACE_H
#define COMMUNICATOR_INTERFACE_H

#include "Command.h"

class CommunicatorInterface
{
public:
    virtual Command_t getCommand() = 0;
};

#endif //COMMUNICATOR_INTERFACE_H
