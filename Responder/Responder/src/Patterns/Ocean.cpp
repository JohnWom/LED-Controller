//
// Created by johnw on 7/23/2023.
//

#include "Ocean.h"

Ocean::Ocean(Adafruit_NeoPixel* leds, int num_leds): Pattern(leds, num_leds, 0, 0, 0) {
}

void Ocean::firstStep() {
    leds->clear();
    leds->show();
}

void Ocean::nextStep() {
    // fill with basic blue
    for (int i=0; i<num_leds; i++) {
        leds->setPixelColor(i, colors[DEEP][0],colors[DEEP][1],colors[DEEP][2]);
    }

    // fill with deep specs
    for (int i=0; i<20; i++) {
        int point = (int) random(300);
        leds->setPixelColor(point, colors[MAIN][0],colors[MAIN][1],colors[MAIN][2]);
    }

    // fill in with waves
    for (int i=0; i<8; i++) {
        int wave_tip = (int) random(300);
        for (int j=0; j<16; j++) {
            int point = wave_tip + j - 8;
            if (random(5) != 0)
                leds->setPixelColor(point, colors[CARIBBEAN][0],colors[CARIBBEAN][1],colors[CARIBBEAN][2]);
        }
        for (int j=0; j<6; j++) {
            int point = wave_tip + j - 3;   // set point 3 pixes back from wave tip
            if (random(4) != 0)
                leds->setPixelColor(point, colors[WAVE_CREST][0],colors[WAVE_CREST][1],colors[WAVE_CREST][2]);
        }

    }
    leds->show();
    delay(300);


}