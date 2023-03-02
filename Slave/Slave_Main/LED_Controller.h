#ifndef LED_CONTROLLER
#define LED_CONTROLLER

#include <Adafruit_NeoPixel.h>

class LED_Controller
{
  public:
    LED_Controller(Adafruit_NeoPixel*, int);

    static void lightAll(int, int, int);

    static void lightOne(int, int, int, int);

    static void setOne(int, int, int, int);

    static void show();

    static int num_leds;

    static Adafruit_NeoPixel* NeoPix;

  friend class Patterns;
};
#endif