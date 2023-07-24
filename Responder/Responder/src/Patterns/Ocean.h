//
// Created by johnw on 7/23/2023.
//

#ifndef OCEAN_H
#define OCEAN_H

#include "PatternInterface.h"
#include <Arduino.h>

class Ocean: public Pattern
{
    enum color_names {DEEP, MAIN, CARIBBEAN, WAVE_CREST, SEA_FOAM};
    int colors[5][3] = {
            {3,4,94},
            {0,119,182},
            {0,180,216},
            {144,224,239},
            {202,240,248}
    };

public:
    Ocean(Adafruit_NeoPixel*, int);

    void firstStep() override;
    void nextStep() override;
};


#endif //OCEAN_H
