//
// Created by johnw on 7/11/2023.
//

#ifndef PLATFORMIO_VERSION_CENTERPULSESPLIT_H
#define PLATFORMIO_VERSION_CENTERPULSESPLIT_H

#include "PatternInterface.h"
#include "../../.pio/libdeps/pico/FastLED/src/pixeltypes.h"

/*
 * This pattern lights groups of 40 LEDs to converge from the 2 edges to the center
 * It splits the string into the groups, and leaves leftover LED's blank.
 * It uses both Primary and Secondary Colors
*/

class CenterPulseSplit: public Pattern
{
public:
    CenterPulseSplit(CRGB *np, int nleds, uint8_t **c);

    void firstStep() override;
    void nextStep() override;

private:
    int num_groups;
    int state;
    int prev_state;
    int max_state;
};


#endif //PLATFORMIO_VERSION_CENTERPULSESPLIT_H
