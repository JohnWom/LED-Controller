//
// Created by johnw on 7/11/2023.
//

#include "ThreeColor.h"

ThreeColor::ThreeColor(Adafruit_NeoPixel *np, int nleds, unsigned short n_r, unsigned short n_g, unsigned short n_b):
    Pattern(np, nleds, n_r, n_g, n_b){
    group_size = 10;
    num_groups = num_leds / group_size;
}

void ThreeColor::firstStep() {
    // Clear the string
    for (int i=0; i<num_leds; i++) {
        leds->setPixelColor(i, 0, 0, 0); // Clear any old pattern out
    }
    leds->show();
    delay(300);
}

void ThreeColor::nextStep() {
    int t_r;
    int t_g;
    int t_b;
        for (int s=0; s<num_groups; s++) {
            if (s%3 == 0) {
                t_r = r;
                t_g = g;
                t_b = b;
            }
            else if (s%3 == 1) {
                t_r = b;
                t_g = r;
                t_b = g;
            }
            else {
                t_r = g;
                t_g = b;
                t_b = r;
            }
            for (int i=0; i<group_size and (i+(s*10))<num_leds; i++)
                leds->setPixelColor((s*10) + i, t_r, t_g, t_b);
        }
    leds->show();
    delay(300);
    int temp = r;
    r = b;
    b = g;
    g = temp;
}