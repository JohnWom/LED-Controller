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
    FunctionSelectable(String, String);

    void execute() override;

    const String &getCommand() const;

    void setCommand(const String &command);

private:
    String command;

};


#endif //FUNCTIONSELECTABLE_H
