//
// Created by johnw on 7/14/2023.
//

#ifndef PARTY1_H
#define PARTY1_H

#include "PatternInterface.h"
#include "CenterPulseSplit.h"
#include "CenterPulseWhole.h"
#include "ThreeColor.h"

class Party1: public Pattern
{
public:
    Party1(CRGB*, int, unsigned short, unsigned short, unsigned short);

    void firstStep() override;
    void nextStep() override;
    void setColors(unsigned short, unsigned short, unsigned short);
private:
    Pattern* p1;
    Pattern* p2;
    Pattern* p3;

    int state;
    int count;
};


#endif //PARTY1_H
