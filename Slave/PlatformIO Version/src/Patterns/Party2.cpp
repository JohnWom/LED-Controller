//
// Created by johnw on 7/14/2023.
//

#include "Party2.h"


Party2::Party2(Adafruit_NeoPixel* leds, int num_leds, unsigned short n_r, unsigned short n_g, unsigned short n_b):
        Pattern(leds, num_leds, n_r, n_g, n_b){
    p2 = new CenterPulseWhole(leds, num_leds, r, g, b);
    p3 = new CenterPulseSplit(leds, num_leds, r, g, b, 1);
    state = 1;
    count = 0;
}

void Party2::firstStep() {
    leds->clear();
    leds->show();
    count = 0;
}

void Party2::nextStep() {
    switch (state) {
        case 1:
            p2->setColors(r, g, b);
            p2->nextStep();
            if (count > (int) (log10(num_leds/2) / log10(2) )) {
                state++;
                p2->firstStep();
                firstStep();
            }
            break;
        case 2:
            p3->setColors(r, g, b);
            p3->nextStep();
            if (count > 5*3) {
                state = 1;
                p3->firstStep();
                firstStep();
            }
            break;
    }
    count++;
}