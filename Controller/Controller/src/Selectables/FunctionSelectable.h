//
// Created by johnw on 7/12/2023.
//

#ifndef FUNCTIONSELECTABLE_H
#define FUNCTIONSELECTABLE_H

#include "SelectableInterface.h"
#include <Arduino.h>

/*
 * This Selectable is used for sending commands to the responder chip
 * The command member should follow a standard pattern
 * Current Patterns in use are:
 *      - C...: Set Color
 *      - K...: Custom Color
 *      - MP..: Music Pattern
 *      - SP..: Static Pattern
*/

class FunctionSelectable: public Selectable
{
public:
    FunctionSelectable(char*, char*);

    void execute() override;

private:
    String command;

public:
    // Getters & Setters
    const String &getCommand() const;
    void setCommand(const char* command);
};


#endif //FUNCTIONSELECTABLE_H
