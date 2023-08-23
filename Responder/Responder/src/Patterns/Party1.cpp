//
// Created by johnw on 7/14/2023.
//

#include "Party1.h"

Party1::Party1(CRGB* leds, int num_leds, uint8_t **c):
    Pattern(leds, num_leds,c),
    p1(new ThreeColor(leds, num_leds, c)),
    p2(new CenterPulseWhole(leds, num_leds, c)),
    p3(new CenterPulseSplit(leds, num_leds, c)),
    state(0),
    count(0)
    {}

void Party1::firstStep() {
    Pattern::firstStep();
    count = 0;
}

void Party1::nextStep() {
    switch (state) {
        case 0:
            p1->nextStep();
            break;
        case 1:
            p2->nextStep();
            if (count > (int) (log10(numLeds / 2) / log10(2) )) {
                state++;
                p2->firstStep();
                firstStep();
            }
            break;
        case 2:
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
