//
// Created by johnw on 7/8/2023.
//

#ifndef PATTERN_INTERFACE_H
#define PATTERN_INTERFACE_H

// Including FastLED this way lets IntelliSense read it
#include "../../.pio/libdeps/pico/FastLED/src/FastLED.h"
#include <Arduino.h>

class Pattern
{
public:
    enum ranking {PRIMARY, SECONDARY, TERTIARY};

    Pattern(CRGB* np, int nleds, uint8_t **c):
            colors(c),
            leds(np),
            numLeds(nleds)
            {}

    virtual void firstStep() {
        // Default First Step is to clear the LEDs
        FastLED.clear();
        FastLED.show();
    }

    virtual void nextStep() = 0;


    virtual ~Pattern() = default;

protected:
    uint8_t **colors;
    CRGB* leds;
    int numLeds;
};

#endif  //PATTERN_INTERFACE_H
