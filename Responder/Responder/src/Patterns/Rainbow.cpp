//
// Created by johnw on 7/11/2023.
//

#include "Rainbow.h"

Rainbow::Rainbow(CRGB *np, int nleds):
        Pattern(np, nleds, 0, 0, 0){
}

void Rainbow::firstStep() {
    fill_solid(leds, num_leds, CRGB::Black);
    FastLED.show();
    delay(300);
}

void Rainbow::nextStep() {
    uint8_t startHue = beat8(10,255);
    fill_rainbow(leds, num_leds, startHue);
    FastLED.show();
    delay(300);

}