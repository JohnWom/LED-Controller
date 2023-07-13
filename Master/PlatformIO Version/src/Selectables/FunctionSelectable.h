//
// Created by johnw on 7/12/2023.
//

#ifndef FUNCTIONSELECTABLE_H
#define FUNCTIONSELECTABLE_H

#include "SelectableInterface.h"
#include <Arduino.h>

class FunctionSelectable: public Selectable
{
public:
    FunctionSelectable(char*, char*);

    void execute() override;

private:
    char* command;
};


#endif //FUNCTIONSELECTABLE_H
