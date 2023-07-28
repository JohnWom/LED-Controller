//
// Created by johnw on 7/11/2023.
//

#ifndef PLATFORMIO_VERSION_THREECOLOR_H
#define PLATFORMIO_VERSION_THREECOLOR_H

#include "PatternInterface.h"
#include "../../.pio/libdeps/pico/FastLED/src/pixeltypes.h"

class ThreeColor: public Pattern
{
public:
    ThreeColor(CRGB *np, int nleds, unsigned short n_r, unsigned short  n_g, unsigned short  n_b);

    void firstStep();
    void nextStep();

private:
    int num_groups;
    int group_size;
};


#endif //PLATFORMIO_VERSION_THREECOLOR_H
