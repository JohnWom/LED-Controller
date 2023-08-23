//
// Created by johnw on 7/14/2023.
//

#include "Party2.h"


Party2::Party2(CRGB* leds, int num_leds, uint8_t **c):
        Pattern(leds, num_leds, c),
        p1(new CenterPulseWhole(leds, num_leds, c)),
        p2(new CenterPulseSplit(leds, num_leds, c)),
        state(0),
        count(0)
        {}

void Party2::firstStep() {
    Pattern::firstStep();
    count = 0;
}

void Party2::nextStep() {
    switch (state) {
        case 1:
            p1->nextStep();
            if (count > (int) (log10(numLeds / 2) / log10(2) )) {
                state++;
                p1->firstStep();
                firstStep();
            }
            break;
        case 2:
            p2->nextStep();
            if (count > 17) {
                state = 1;
                p2->firstStep();
                firstStep();
            }
            break;
    }
    count++;
}