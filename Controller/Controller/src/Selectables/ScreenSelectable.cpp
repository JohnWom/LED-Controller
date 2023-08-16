//
// Created by johnw on 7/12/2023.
//

#include "ScreenSelectable.h"

ScreenSelectable::ScreenSelectable(char *t):
        Selectable(t)
{}

ScreenSelectable::ScreenSelectable(char* t, Screen* s, callback_t c):
        Selectable(t),
        nextScreen(s),
        callback(c)
        {}

void ScreenSelectable::execute() {
    callback(nextScreen);
}

Screen *ScreenSelectable::getNextScreen() const {
    return nextScreen;
}

void ScreenSelectable::setNextScreen(Screen *s) {
    nextScreen = s;
}

void ScreenSelectable::setCallback(callback_t c) {
    callback = c;
}

