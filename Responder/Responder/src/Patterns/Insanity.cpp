//
// Created by johnw on 7/24/2023.
//

#include "Insanity.h"

Insanity::Insanity(CRGB* l, int leds):
    Pattern(l, leds)
    {}


void Insanity::nextStep() {
    for (int i=0; i < numLeds; i++)
        leds[i].setRGB(random8(), random8(), random8());
    FastLED.show();
    delay(333);
}