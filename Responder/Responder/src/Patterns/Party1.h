//
// Created by johnw on 7/14/2023.
//

#ifndef PARTY1_H
#define PARTY1_H

#include "PatternInterface.h"
#include "CenterPulseSplit.h"
#include "CenterPulseWhole.h"
#include "ThreeColor.h"

/*
 * This class is a combination of other patterns
 * It combines:
 *      ThreeColor
 *      CenterPulseWhole
 *      CenterPulseSplit
*/

class Party1: public Pattern
{
public:
    Party1(CRGB*, int, colors_t);

    void firstStep() override;
    void nextStep() override;

private:
    Pattern* p1;
    Pattern* p2;
    Pattern* p3;

    int state;
    int count;
};


#endif //PARTY1_H
