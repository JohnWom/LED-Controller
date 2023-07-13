//
// Created by johnw on 7/12/2023.
//

#ifndef PLATFORMIO_VERSION_NUMBERSELECTABLE_H
#define PLATFORMIO_VERSION_NUMBERSELECTABLE_H

#include "SelectableInterface.h"
#include <Arduino.h>

class NumberSelectable: public Selectable
{
public:
    enum types {HUE, SAT, V};
    NumberSelectable(char*, int, int, int);

    void execute() override;
    void rightScroll() override;
    void leftScroll() override;

private:
    int val;
    int minV;
    int maxV;
    int type;
};


#endif //PLATFORMIO_VERSION_NUMBERSELECTABLE_H
