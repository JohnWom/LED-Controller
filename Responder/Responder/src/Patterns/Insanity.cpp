//
// Created by johnw on 7/24/2023.
//

#include "Insanity.h"

Insanity::Insanity(CRGB* l, int leds): Pattern(l, leds, 0, 0, 0) {

}

void Insanity::firstStep() {
    fill_solid(leds, num_leds, CRGB::Black);
    FastLED.show();
}

void Insanity::nextStep() {
    for (int i=0; i<num_leds; i++)
        leds[i].setRGB(random(255), random(255), random(255));
    FastLED.show();
    delay(300);
}