//
// Created by johnw on 7/24/2023.
//

#include "Insanity.h"

Insanity::Insanity(Adafruit_NeoPixel* l, int leds): Pattern(l, leds, 0, 0, 0) {

}

void Insanity::firstStep() {
    leds->clear();
    leds->show();
}

void Insanity::nextStep() {
    for (int i=0; i<num_leds; i++)
        leds->setPixelColor(i, random(255), random(255), random(255));
    leds->show();
    delay(300);
}