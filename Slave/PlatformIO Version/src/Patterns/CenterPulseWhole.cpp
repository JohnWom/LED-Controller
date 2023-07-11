//
// Created by johnw on 7/10/2023.
//

#include "CenterPulseWhole.h"

CenterPulseWhole::CenterPulseWhole(Adafruit_NeoPixel *l, int num_leds, unsigned short r, unsigned short g, unsigned short b):
    Pattern(l, num_leds, r, g, b) {
    state = 0;
    prev = 0;
    max_state = num_leds / 2;
    Serial.println(max_state);
}

void CenterPulseWhole::firstStep() {
    // Clear the string
    for (int i=0; i<num_leds; i++) {
        leds->setPixelColor(i, 0, 0, 0); // Clear any old pattern out
    }
    leds->show();
    delay(300);

    prev = state + 1;
    state++;
}

void CenterPulseWhole::nextStep() {
    // Move inward graudally faster
    for (int i=prev; i<=state and i < max_state; i++) {
        leds->setPixelColor(i, r, g, b);
        leds->setPixelColor(num_leds-i-1, r, g, b);
    }
    leds->show();
    delay(300);

    if (state>max_state) {
        state = 0;
        prev = 0;
        firstStep();
    }
    prev = state+1;
    state += state;
}