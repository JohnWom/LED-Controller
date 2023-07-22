//
// Created by johnw on 7/12/2023.
//

#include "FunctionSelectable.h"

FunctionSelectable::FunctionSelectable(String t, String m):
        Selectable(t, nullptr, nullptr){
    command = m;
}

void FunctionSelectable::execute() {
    Serial1.print(command);
}

const String &FunctionSelectable::getCommand() const {
    return command;
}

void FunctionSelectable::setCommand(const String &command) {
    FunctionSelectable::command = command;
}
