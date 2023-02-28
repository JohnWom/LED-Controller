#ifndef LED_CONTROLLER
#define LED_CONTROLLER

#include <Adafruit_NeoPixel.h>

class LED_Controller
{
  public:
    LED_Controller(Adafruit_NeoPixel*, int);

    void lightAll(int, int, int);

    void lightOne(int, int, int, int);

    void setOne(int, int, int, int);

    void show();

  private:
    int num_leds;
    Adafruit_NeoPixel* pixels;

  friend class Patterns;
};
#endif