//
// Created by johnw on 7/8/2023.
//

#ifndef PLATFORMIO_VERSION_SOLIDCOLOR_H
#define PLATFORMIO_VERSION_SOLIDCOLOR_H

#include "PatternInterface.h"

class SolidColor: public Pattern{
public:
    SolidColor(CRGB* np, int nleds, unsigned short n_r, unsigned short  n_g, unsigned short  n_b);

    void firstStep() override;
    void nextStep() override;
};


#endif //PLATFORMIO_VERSION_SOLIDCOLOR_H
