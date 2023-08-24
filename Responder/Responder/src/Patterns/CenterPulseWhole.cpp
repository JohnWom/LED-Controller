//
// Created by johnw on 7/10/2023.
//

#include "CenterPulseWhole.h"

CenterPulseWhole::CenterPulseWhole(CRGB *l, int num_leds, colors_t c):
    Pattern(l, num_leds, c),
    state(1),
    prev(1),
    max_state(num_leds / 2)
    {}

void CenterPulseWhole::firstStep() {
    // Clear the string
    Pattern::firstStep();
    delay(333);

    prev = state + 1;
    state++;
}

void CenterPulseWhole::nextStep() {
    // Move inward graudally faster
    for (int i=prev; i<=state and i < max_state; i++) {
        leds[i] = colors->get(PRIMARY);
        leds[numLeds - i - 1] = colors->get(PRIMARY);
    }
    FastLED.show();
    delay(333);

    if (state>max_state) {
        state = 0;
        prev = 0;
        firstStep();
    }
    prev = state+1;
    state += state;
}