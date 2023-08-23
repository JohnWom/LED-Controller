//
// Created by johnw on 7/24/2023.
//

#ifndef INSANITY_H
#define INSANITY_H

#include "PatternInterface.h"

/*
 *  This pattern simply sets every LED to a random RGB value
*/


class Insanity: public Pattern
{
public:
    Insanity(CRGB*, int);

    void nextStep() override;
};


#endif //INSANITY_H
