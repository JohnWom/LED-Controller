//
// Created by johnw on 7/8/2023.
//

#include "SolidColor.h"

SolidColor::SolidColor(Adafruit_NeoPixel* np, int nleds, unsigned short n_r, unsigned short n_g, unsigned short n_b) : Pattern(np, nleds, n_r, n_g, n_b) {

}

void SolidColor::firstStep() {
    for (int i=0; i<num_leds; i++) {
        leds->setPixelColor(i, r, g, b);
    }
    leds->show();
    delay(300);
}

void SolidColor::nextStep() {
    firstStep();
}