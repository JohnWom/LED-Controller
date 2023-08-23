//
// Created by johnw on 7/14/2023.
//

#ifndef PLATFORMIO_VERSION_PARTY2_H
#define PLATFORMIO_VERSION_PARTY2_H

#include "PatternInterface.h"
#include "CenterPulseSplit.h"
#include "CenterPulseWhole.h"
#include "ThreeColor.h"

/*
 * This pattern combines other subpatterns
 * This pattern combines:
 *      CenterPulseWhole
 *      CenterPulseSplit
*/

class Party2: public Pattern
{
public:
    Party2(CRGB*, int, uint8_t **);

    void firstStep() override;
    void nextStep() override;

private:
    Pattern* p1;
    Pattern* p2;

    int state;
    int count;
};


#endif //PLATFORMIO_VERSION_PARTY2_H
