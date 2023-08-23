//
// Created by johnw on 7/23/2023.
//

#include "Ocean.h"

Ocean::Ocean(CRGB* leds, int num_leds):
    Pattern(leds, num_leds),
    state(0)
    {}

void Ocean::firstStep() {
    for (int i=0; i<num_waves; i++) {
        wavePoints[i] = random(300);
    }
    calm();
    FastLED.show();
}

void Ocean::nextStep() {

    switch(state) {
        case 0 ... 4:
            calm();
            break;
        case 5:
            beginning();
            break;
        case 6:
            swelling();
            break;
        case 7:
            peak();
            break;
        case 8:
            swelling();
            break;
        case 9:
            beginning();
            break;
        case 10:
            firstStep();
            break;
    }
    state = (state + 1) % 11;
    FastLED.show();
    delay(400);

}

void Ocean::calm() {
    int color[3] = {colors[DEEP][0],colors[DEEP][1],colors[DEEP][2]};
    // fill with basic blue
    for (int i=0; i < numLeds; i++) {
        leds[i] = CRGB(color[0],color[1],color[2] + random(-20, 20));
    }

    // fill with deep specs
    for (int i=0; i<20; i++) {
        int point = (int) random(300);
        leds[point] = CRGB(colors[DEEP][0],colors[DEEP][1],colors[DEEP][2]-20);
    }
}

void Ocean::beginning() {
    calm();
    int color[3] = {colors[MAIN][0], colors[MAIN][1], colors[MAIN][2]};
    for (int i=0; i<num_waves; i++) {
        // fill around the waves with brighter blues
        for (int j=-6; j<=6; j++) {
            if ((int) random(8) != 0)
                leds[wavePoints[i] + j] = CRGB(color[0] + random(20), color[1], color[2] + random(10));
        }
    }
}

void Ocean::swelling() {
    beginning();
    int color[3] = {colors[CARIBBEAN][0], colors[CARIBBEAN][1], colors[CARIBBEAN][2]};
    for (int i=0; i<num_waves; i++) {
        for (int j=-1; j<=1; j++) {
            if ((int) random(8) != 0)
                leds[wavePoints[i] + j] = CRGB(color[0] + random(20), color[1], color[2]);
        }
    }
}

void Ocean::peak() {
    beginning();
    int color[3] = {colors[SEA_FOAM][0], colors[SEA_FOAM][1], colors[SEA_FOAM][2]};
    for (int i=0; i<num_waves; i++) {
        for (int j=-2; j<=2; j++) {
            if ((int) random(8) != 0)
                leds[wavePoints[i] + j] = CRGB(color[0] + random(20), color[1], color[2]);
        }
        leds[wavePoints[i]] = CRGB(colors[WAVE_CREST][0],colors[WAVE_CREST][1],colors[WAVE_CREST][2]);
    }
}