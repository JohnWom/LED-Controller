//
// Created by johnw on 7/8/2023.
//

#ifndef PATTERN_INTERFACE_H
#define PATTERN_INTERFACE_H

#include <Adafruit_NeoPixel.h>

class Pattern
{
public:
    Pattern(Adafruit_NeoPixel* np, int nleds, unsigned short n_r, unsigned short  n_g, unsigned short  n_b) {
        r = n_r;
        g = n_g;
        b = n_b;
        leds = np;
        num_leds = nleds;
    }
    virtual void firstStep() = 0;
    virtual void nextStep() = 0;
    void setColors(unsigned short n_r, unsigned short  n_g, unsigned short  n_b) {
        r = n_r;
        g = n_g;
        b = n_b;
    }

    virtual ~Pattern()= default;
    void invertColors() {
        r = 255-r;
        g = 255-g;
        b = 255-b;
    }
protected:
    unsigned short r;
    unsigned short g;
    unsigned short b;
    Adafruit_NeoPixel* leds;
    int num_leds;
};

#endif  //PATTERN_INTERFACE_H
