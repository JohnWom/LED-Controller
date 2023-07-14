//
// Created by johnw on 7/12/2023.
//

#include "ScreenSelectable.h"

ScreenSelectable::ScreenSelectable(char *t, Screen* s, Operator* o):
        Selectable(t, nullptr, nullptr){
    nextScreen = s;
    op = o;
}

void ScreenSelectable::execute() {
    op->callback(nextScreen);
}

Screen *ScreenSelectable::getNextScreen() const {
    return nextScreen;
}

void ScreenSelectable::setNextScreen(Screen *s) {
    nextScreen = s;
}

Operator *ScreenSelectable::getOp() const {
    return op;
}

void ScreenSelectable::setOp(Operator *op) {
    ScreenSelectable::op = op;
}
