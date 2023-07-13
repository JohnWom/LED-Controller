//
// Created by johnw on 7/12/2023.
//

#include "NumberSelectable.h"

NumberSelectable::NumberSelectable(char *t, int min, int max, int tp):
        Selectable(t, nullptr, nullptr){
    val = 0;
    minV = min;
    maxV = max;
    type = tp;
}

void NumberSelectable::execute() {
    String msg = "C";
    String stub = "---";
    if (type == HUE){
        msg += String(val);
        msg += stub;
        msg += stub;
    } else if (type == SAT) {
        msg += stub;
        msg += String(val);
        msg += stub;
    } else if (type == V) {
        msg += stub;
        msg += stub;
        msg += String(val);
    }
    Serial1.print(msg);
}

void NumberSelectable::rightScroll() {
    if ((val + 1) <= maxV)
        val++;
}

void NumberSelectable::leftScroll() {
    if ((val - 1) <= minV)
        val--;
}