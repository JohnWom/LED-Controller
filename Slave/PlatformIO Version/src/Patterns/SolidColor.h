//
// Created by johnw on 7/8/2023.
//

#ifndef PLATFORMIO_VERSION_SOLIDCOLOR_H
#define PLATFORMIO_VERSION_SOLIDCOLOR_H

#include "PatternInterface.h"

class SolidColor: PatternInterface{

    void first_step() override;
    void next_step() override;
};


#endif //PLATFORMIO_VERSION_SOLIDCOLOR_H
