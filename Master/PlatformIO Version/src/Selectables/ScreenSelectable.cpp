//
// Created by johnw on 7/12/2023.
//

#include "ScreenSelectable.h"

ScreenSelectable::ScreenSelectable(char *t, Screen* s, void (*c)(Screen *), Selectable *n, Selectable *p):
        Selectable(t, n, p){
    nextScreen = s;
    callback = c;
}

void ScreenSelectable::execute() {
    callback(nextScreen);
}