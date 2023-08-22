//
// Created by johnw on 7/14/2023.
//

#include "Party1.h"

Party1::Party1(CRGB* leds, int num_leds, unsigned short n_r, unsigned short n_g, unsigned short n_b):
    Pattern(leds, num_leds, n_r, n_g, n_b){
    p1 = new ThreeColor(leds, num_leds, r, g, b);
    p2 = new CenterPulseWhole(leds, num_leds, r, g, b);
    p3 = new CenterPulseSplit(leds, num_leds, r, g, b, 1);
    state = 0;
    count = 0;
}

void Party1::firstStep() {
    fill_solid(leds, numLeds, CRGB::Black);
    FastLED.show();
    count = 0;
}

void Party1::nextStep() {
    switch (state) {
        case 0:
            p1->nextStep();
            if (count > 6) {
                p1->setColors(r, g, b);
                state++;
                firstStep();
            }
            break;
        case 1:
            p2->setColors(r, g, b);
            p2->nextStep();
            if (count > (int) (log10(numLeds / 2) / log10(2) )) {
                state++;
                p2->firstStep();
                firstStep();
            }
            break;
        case 2:
            p3->setColors(r, g, b);
            p3->nextStep();
            if (count > 5) {
                state = 0;
                p3->firstStep();
                firstStep();
            }
            break;
    }
    count++;
}
