//
// Created by johnw on 7/8/2023.
//

#ifndef COMMUNICATOR_INTERFACE_H
#define COMMUNICATOR_INTERFACE_H

#include "Command.h"

class Communicator
{
public:
    virtual Command_t getCommand() = 0;

    virtual ~Communicator()= default;
};

#endif //COMMUNICATOR_INTERFACE_H
