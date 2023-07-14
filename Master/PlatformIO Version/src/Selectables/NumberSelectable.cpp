//
// Created by johnw on 7/12/2023.
//

#include "NumberSelectable.h"

NumberSelectable::NumberSelectable(char *t, int min, int max, int tp):
        Selectable(t, nullptr, nullptr){
    val = 125;
    minV = min;
    maxV = max;
    type = tp;
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
    //refresh();

}

void NumberSelectable::leftScroll() {
    Serial.println("Decrementing");
    if ((val - 1) >= minV)
        val--;
    //refresh();
}

void NumberSelectable::refresh() {
    Serial.println("Starting refresh");
    // Clear the old numbers
    char* test = "Red         123";
    for (int i=12; i<12; i++)
        test[i] = ' ';
    Serial.println(test);
    // Write the new ones in
    int tmp = val;
    int i = 14;
    do {
        test[i--] = tmp % 10 + '0';
        tmp /= 10;
    } while(tmp > 0);
    Serial.println(test);
}