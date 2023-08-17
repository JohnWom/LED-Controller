//
// Created by johnw on 7/12/2023.
//

#include "ScreenSelectable.h"

ScreenSelectable::ScreenSelectable(char *t, ScreenManager &sm):
        Selectable(t),
        nextScreen(),
        screenManager(sm)
{}

ScreenSelectable::ScreenSelectable(char* t, Screen* s, ScreenManager &sm):
        Selectable(t),
        nextScreen(s),
        screenManager(sm)
        {}

void ScreenSelectable::execute() {
    screenManager.callback(nextScreen);
}

Screen *ScreenSelectable::getNextScreen() const {
    return nextScreen;
}

void ScreenSelectable::setNextScreen(Screen *s) {
    nextScreen = s;
}