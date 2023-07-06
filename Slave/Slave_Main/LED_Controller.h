#ifndef LED_CONTROLLER
#define LED_CONTROLLER

#include <Adafruit_NeoPixel.h>

// Static Class LED_Controller
// Wrapper Class for Adafruit Neopixel Library to simple pattern creation
// Also static due to use by Thread

class LED_Controller
{
  public:

    // light- Functions show change immediatly
    static void lightAll(int, int, int);

    static void lightOne(int, int, int, int);

    // set Functions change color but does not show change yet, must call show() to see change
    static void setOne(int, int, int, int);

    static void setBrightness(int);

    static void show();

    static int num_leds;

    static Adafruit_NeoPixel* NeoPix;

  friend class Patterns;
};
#endif