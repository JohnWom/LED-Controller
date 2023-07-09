//
// Created by johnw on 7/8/2023.
//

#include "SolidColor.h"

void SolidColor::first_step() {
    for (int i=0; i<num_leds; i++)
        leds->setPixelColor(i, r, g, b);
    leds->show();
}

void SolidColor::next_step() {
    first_step();
}