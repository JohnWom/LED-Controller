//
// Created by johnw on 7/8/2023.
//

#include "SolidColor.h"

SolidColor::SolidColor(CRGB* np, int nleds, colors_t c):
    Pattern(np, nleds, c)
    {}


void SolidColor::nextStep() {
    fill_solid(leds, numLeds, colors->get(PRIMARY));
    FastLED.show();
}