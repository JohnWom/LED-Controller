//
// Created by johnw on 7/12/2023.
//

#include "CustomRGBSelectable.h"

CustomRGBSelectable::CustomRGBSelectable(char* t, int min, int max, int tp):
    Selectable(t),
    val(max / 2),
    minV(min),
    maxV(max),
    type(tp)
    {
    // functions can't be run outside of setup & loop, so refresh is just copied
    // this builds the shown text, placing the value at the end
    String num = String(val);
    text = text.substring(0, 15-num.length());
    text += num;
    }

void CustomRGBSelectable::execute() {
    String msg = "K";       // C is taken by regular colors
    String stub = "---";    // This is the blank that replaces the other RGB values
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

void CustomRGBSelectable::rightScroll() {
    Serial.println("Incrementing...");
    if ((val + 1) <= maxV)
        val++;
    refresh();
}

void CustomRGBSelectable::leftScroll() {
    Serial.println("Decrementing");
    if ((val - 1) >= minV)
        val--;
    refresh();
}

void CustomRGBSelectable::refresh() {
    // This refreshes the screen to reflect the change in number
    Serial.println("Starting refresh");
    String num = String(val);
    text.setCharAt(12, ' ');
    text.setCharAt(13, ' ');
    text.setCharAt(14, ' ');
    text = text.substring(0, 15-num.length());
    text += num;

}