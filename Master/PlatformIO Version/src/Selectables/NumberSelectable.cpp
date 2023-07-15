//
// Created by johnw on 7/12/2023.
//

#include "NumberSelectable.h"

NumberSelectable::NumberSelectable(String t, int min, int max, int tp):
        Selectable(t, nullptr, nullptr){
    val = 125;
    minV = min;
    maxV = max;
    type = tp;

    // functions can't be run outside of setup & loop, so refresh is just copied
    String num = String(val);
    text = text.substring(0, 15-num.length());
    text += num;
}

void NumberSelectable::execute() {
    String msg = "K";
    String stub = "---";
    if (type == R){
        msg += String(val);
        msg += stub;
        msg += stub;
    } else if (type == G) {
        msg += stub;
        msg += String(val);
        msg += stub;
    } else if (type == B) {
        msg += stub;
        msg += stub;
        msg += String(val);
    }
    Serial1.println(msg);
}

void NumberSelectable::rightScroll() {
    Serial.println("Incrementing...");
    if ((val + 1) <= maxV)
        val++;
    refresh();
}

void NumberSelectable::leftScroll() {
    Serial.println("Decrementing");
    if ((val - 1) >= minV)
        val--;
    refresh();
}

void NumberSelectable::refresh() {
    Serial.println("Starting refresh");
    String num = String(val);
    text = text.substring(0, 15-num.length());
    text += num;

}