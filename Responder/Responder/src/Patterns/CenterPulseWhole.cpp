//
// Created by johnw on 7/10/2023.
//

#include "CenterPulseWhole.h"

CenterPulseWhole::CenterPulseWhole(CRGB *l, int num_leds, unsigned short r, unsigned short g, unsigned short b):
    Pattern(l, num_leds, r, g, b) {
    state = 0;
    prev = 0;
    max_state = num_leds / 2;
    prev = state + 1;
    state++;
}

void CenterPulseWhole::firstStep() {
    // Clear the string
    fill_solid(leds, num_leds, CRGB::Black);
    FastLED.show();
    delay(300);

    prev = state + 1;
    state++;
}

void CenterPulseWhole::nextStep() {
    // Move inward graudally faster
    for (int i=prev; i<=state and i < max_state; i++) {
        leds[i].setRGB(r, g, b);
        leds[num_leds-i-1].setRGB(r, g, b);
    }
    FastLED.show();
    delay(300);

    if (state>max_state) {
        state = 0;
        prev = 0;
        firstStep();
    }
    prev = state+1;
    state += state;
}