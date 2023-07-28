//
// Created by johnw on 7/14/2023.
//

#ifndef PLATFORMIO_VERSION_PARTY2_H
#define PLATFORMIO_VERSION_PARTY2_H

#include "PatternInterface.h"
#include "CenterPulseSplit.h"
#include "CenterPulseWhole.h"
#include "ThreeColor.h"

class Party2: public Pattern
{
public:
    Party2(CRGB*, int, unsigned short, unsigned short, unsigned short);

    void firstStep() override;
    void nextStep() override;
    void setColors(unsigned short, unsigned short, unsigned short);
private:
    Pattern* p2;
    Pattern* p3;

    int state;
    int count;
};


#endif //PLATFORMIO_VERSION_PARTY2_H
