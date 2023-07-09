//
// Created by johnw on 7/8/2023.
//

#ifndef PATTERN_INTERFACE_H
#define PATTERN_INTERFACE_H

#include <Adafruit_Neopixel.h>

class PatternInterface
{
public:
    PatternInterface(Adafruit_NeoPixel* np, int nleds, unsigned short n_r, unsigned short  n_g, unsigned short  n_b) {
        r = n_r;
        g = n_g;
        b = n_b;
        leds = np;
        num_leds = nleds;
    }
    virtual void first_step() = 0;
    virtual void next_step() = 0;
    void set_colors(unsigned short n_r, unsigned short  n_g, unsigned short  n_b) {
        r = n_r;
        g = n_g;
        b = n_b;
    }

protected:
    unsigned short r;
    unsigned short g;
    unsigned short b;
    Adafruit_NeoPixel* leds;
    int num_leds;
};


#endif  //PATTERN_INTERFACE_H
