//
// Created by johnw on 7/8/2023.
//

#include "SolidColor.h"

SolidColor::SolidColor(CRGB* np, int nleds, uint8_t **c):
    Pattern(np, nleds, c)
    {}


void SolidColor::nextStep() {
    fill_solid(
leds,
numLeds,
    CRGB(
        colors[PRIMARY][0],
        colors[PRIMARY][1],
        colors[PRIMARY][2]
    ));
    FastLED.show();
}