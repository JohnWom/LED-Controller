//
// Created by johnw on 7/11/2023.
//

#include "CenterPulseSplit.h"

CenterPulseSplit::CenterPulseSplit(Adafruit_NeoPixel* np, int nleds, unsigned short n_r, unsigned short  n_g, unsigned short  n_b, int i):
        Pattern(np, nleds, n_r, n_g, n_b) {
    num_groups = num_leds / 40;
    max_state = 20;
    invert = i;
    state = 1;
    prev_state = 0;
}

void CenterPulseSplit::firstStep() {
    // Clear the string
    for (int i=0; i<num_leds; i++) {
        leds->setPixelColor(i, 0, 0, 0); // Clear any old pattern out
    }
    leds->show();
    delay(300);

    state = 1;
    prev_state = 0;
}

void CenterPulseSplit::nextStep() {
    int s;
    for (s=0; s<num_groups; s++){
        if (invert == 1)
            invertColors();

        for (int i=prev_state; i < state and i <= max_state; i++){
            leds->setPixelColor((40*s) + i, r, g, b);
            leds->setPixelColor((40*s) + 40 - i, r, g, b);
        }
    }
    leds->show();
    delay(300);

    if (invert == 1 && s % 2 == 1)
        invertColors();

    if (state > max_state)
        firstStep();
    else {
        prev_state = state;
        state += state;
    }


}
