#include "LED_Controller.h"

LED_Controller::LED_Controller(Adafruit_NeoPixel* p, int n)
{
  pixels = p;
  num_leds = n;
}

void LED_Controller::lightAll(int r, int g, int b)
{
  for (int i=0; i < num_leds; i++) {
    pixels->setPixelColor(i, r, g, b);
  }
  pixels->show();
}

void LED_Controller::lightOne(int i, int r, int g, int b)
{
  // Make it impossible to set LED beyond range. Arduino does not allow for error throwing :(
  if (i >= num_leds || i < 0)
    return;

  pixels->setPixelColor(i, r, g, b);
  pixels->show();
}

void LED_Controller::setOne(int i, int r, int g, int b)
{
  if (i >= num_leds || i < 0)
    return;

  pixels->setPixelColor(i, r, g, b);
}

void LED_Controller::show() {
  pixels->show();
}