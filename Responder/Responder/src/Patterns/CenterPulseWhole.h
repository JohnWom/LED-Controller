//
// Created by johnw on 7/10/2023.
//

#ifndef PLATFORMIO_VERSION_CENTERPULSEWHOLE_H
#define PLATFORMIO_VERSION_CENTERPULSEWHOLE_H

#include "PatternInterface.h"

/*
 * This pattern lights the entire to converge from the 2 edges to the center
*/


class CenterPulseWhole: public Pattern
{
public:
    CenterPulseWhole(CRGB* , int , colors_t);

    void firstStep() override;
    void nextStep() override;

private:
    int state;  // helps keep track of where in pattern we are
    int prev;
    int max_state;
};


#endif //PLATFORMIO_VERSION_CENTERPULSEWHOLE_H
