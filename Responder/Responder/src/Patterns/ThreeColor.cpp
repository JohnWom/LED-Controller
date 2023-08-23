//
// Created by johnw on 7/11/2023.
//

#include "ThreeColor.h"
#include "../../.pio/libdeps/pico/FastLED/src/pixeltypes.h"

ThreeColor::ThreeColor(CRGB *np, int nleds, uint8_t **c):
    Pattern(np, nleds, c),
    groupSize(10),
    numGroups(),
    state(0)
    {
    numGroups = numLeds / groupSize;
    }


void ThreeColor::nextStep() {
    int type;
    for (int s=0; s < numGroups; s++) {
        if (s%3 == 0)
            type = PRIMARY;
        else if (s%3 == 1)
            type = SECONDARY;
        else {
            type = TERTIARY;
        }
        for (int i=0; i < groupSize and (state + i + (s * 10)) < numLeds; i++)
            leds[state + (s*10) + i] = CRGB(colors[type][0],colors[type][1],colors[type][2]);
    }
    FastLED.show();
    state = (state + 1) % numLeds;
    delay(333);
}