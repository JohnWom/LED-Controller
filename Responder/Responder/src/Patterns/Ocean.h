//
// Created by johnw on 7/23/2023.
//

#ifndef OCEAN_H
#define OCEAN_H

#include "PatternInterface.h"
#include <Arduino.h>

class Ocean: public Pattern
{
    enum color_names {DEEP, MAIN, CARIBBEAN, SEA_FOAM, WAVE_CREST};
    int colors[5][3] = {
            {3,4,80},
            {2,62,118},
            {0,119,182},
            {0,180,216},
            {144,224,239}
    };
     int num_waves = 8;

public:
    Ocean(Adafruit_NeoPixel*, int);

    void firstStep() override;
    void nextStep() override;

private:
    void calm();
    void beginning();
    void swelling();
    void peak();

    int state;

    int wavePoints[8];
};


#endif //OCEAN_H
