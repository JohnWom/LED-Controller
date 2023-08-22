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
    ThreeColor(CRGB *np, int nleds, uint8_t **c);

    void nextStep() override;

private:
    int numGroups;
    int groupSize;
    int state;
};


#endif //PLATFORMIO_VERSION_THREECOLOR_H
