//
// Created by johnw on 7/11/2023.
//

#ifndef PLATFORMIO_VERSION_CENTERPULSESPLIT_H
#define PLATFORMIO_VERSION_CENTERPULSESPLIT_H

#include "PatternInterface.h"
#include "../../.pio/libdeps/pico/FastLED/src/pixeltypes.h"

class CenterPulseSplit: public Pattern
{
public:
    CenterPulseSplit(CRGB *np, int nleds, unsigned short n_r, unsigned short  n_g, unsigned short  n_b, int);
    void firstStep();
    void nextStep();
private:
    void invert_c();

    int num_groups;
    int state;
    int prev_state;
    int max_state;
    int invert;
};


#endif //PLATFORMIO_VERSION_CENTERPULSESPLIT_H
