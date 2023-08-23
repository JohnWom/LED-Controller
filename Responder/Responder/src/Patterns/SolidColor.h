//
// Created by johnw on 7/8/2023.
//

#ifndef PLATFORMIO_VERSION_SOLIDCOLOR_H
#define PLATFORMIO_VERSION_SOLIDCOLOR_H

#include "PatternInterface.h"

/*
 * This pattern just lights the whole string to the Primary Color
*/


class SolidColor: public Pattern{
public:
    SolidColor(CRGB* np, int nleds, uint8_t **c);

    void nextStep() override;
};


#endif //PLATFORMIO_VERSION_SOLIDCOLOR_H
