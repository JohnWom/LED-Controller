//
// Created by johnw on 7/12/2023.
//

#include "FunctionSelectable.h"

FunctionSelectable::FunctionSelectable(char *t, char* m):
        Selectable(t, nullptr, nullptr){
    command = m;
}

void FunctionSelectable::execute() {
    Serial1.print(command);
}