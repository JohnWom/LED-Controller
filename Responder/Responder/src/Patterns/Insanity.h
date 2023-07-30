//
// Created by johnw on 7/24/2023.
//

#ifndef INSANITY_H
#define INSANITY_H

#include "PatternInterface.h"

class Insanity: public Pattern
{
public:
    Insanity(CRGB*, int);

    void firstStep() override;
    void nextStep() override;
};


#endif //INSANITY_H
