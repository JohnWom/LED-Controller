//
// Created by johnw on 7/11/2023.
//

#ifndef PLATFORMIO_VERSION_RAINBOW_H
#define PLATFORMIO_VERSION_RAINBOW_H

#include "PatternInterface.h"

class Rainbow: public Pattern
{
public:
    Rainbow(CRGB* np, int nleds);

    void nextStep() override;

private:
};


#endif //PLATFORMIO_VERSION_RAINBOW_H
