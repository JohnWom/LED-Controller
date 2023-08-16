//
// Created by johnw on 7/12/2023.
//

#include "FunctionSelectable.h"

FunctionSelectable::FunctionSelectable(char* t, char* m):
        Selectable(t),
        command(m)
        {}

void FunctionSelectable::execute() {
    Serial1.print(command); // Send command to responder chip
}

const String &FunctionSelectable::getCommand() const {
    return command;
}

void FunctionSelectable::setCommand(const char* command) {
    FunctionSelectable::command = command;
}
