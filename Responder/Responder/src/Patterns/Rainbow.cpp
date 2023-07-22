//
// Created by johnw on 7/11/2023.
//

#include "Rainbow.h"

Rainbow::Rainbow(Adafruit_NeoPixel *np, int nleds):
        Pattern(np, nleds, 0, 0, 0){
    state = 0;
}

void Rainbow::firstStep() {
    leds->clear();
    leds->show();
    delay(300);
}

void Rainbow::nextStep() {
    leds->rainbow(state,1,255,40, false);
    leds->show();
    delay(300);
    state = (state + 3000);
    if (state > 65535)
        state = 0;
}