//
// Created by johnw on 7/10/2023.
//

#ifndef PLATFORMIO_VERSION_CENTERPULSEWHOLE_H
#define PLATFORMIO_VERSION_CENTERPULSEWHOLE_H

#include "PatternInterface.h"

class CenterPulseWhole: public Pattern
{
public:
    CenterPulseWhole(Adafruit_NeoPixel* , int , unsigned short, unsigned short  , unsigned short);
    void firstStep();
    void nextStep();

private:
    int state;  // helps keep track of where in pattern we are
    int prev;
    int max_state;
};


#endif //PLATFORMIO_VERSION_CENTERPULSEWHOLE_H
