#include "LED_Controller.h"

// light- Functions show change immediatly
void LED_Controller::lightAll(int r, int g, int b)
{
  for (int i=0; i < num_leds; i++) {
    NeoPix->setPixelColor(i, r, g, b);
  }
  NeoPix->show();
}

void LED_Controller::lightOne(int i, int r, int g, int b)
{
  // Make it impossible to set LED beyond range. Arduino does not allow for error throwing :(
  if (i >= num_leds || i < 0)
    return;

  NeoPix->setPixelColor(i, r, g, b);
  NeoPix->show();
}

void LED_Controller::setBrightness(int b) {
  if (b >= 0 && b <= 255) {
    NeoPix->setBrightness(b);
  }
  else {
    Serial.println("Brightness Value not in range 0-255");
  }
}

// set Functions change color but does not show change yet, must call show() to see change
void LED_Controller::setOne(int i, int r, int g, int b)
{
  // Make it impossible to set LED beyond range
  if (i >= num_leds || i < 0)
    return;

  NeoPix->setPixelColor(i, r, g, b);
}

void LED_Controller::show() {
  NeoPix->show();
}