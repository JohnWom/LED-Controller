#include "patterns.h"

Patterns::Patterns(LED_Controller* L, AudioProcessor* P)b         
{

  r = 0;
  g = 0;
  b = 0;
}

// Static Patterns =============================================================================================
//==============================================================================================================

//Solid Color --------------------------------------------------------------------------------------------------
void Patterns::Solid_Color() {
    LED_Controller::lightAll(r, g, b);
}

//Fishpole --------------------------------------------------------------------------------------------------
void Patterns::Color_Cycle() {
  int colors[12][3] = {
    {255,0,0},
    {255,127,0},
    {255,255,0},
    {127,255,0},
    {0,255,0},
    {0,255,127},
    {0,255,255},
    {0,127,255},
    {0,0,255},
    {127,0,255},
    {255,0,255},
    {255,0,127}
  };
  int color_num = 0;

  for (int i = 0; i < LED_Controller::num_leds; i++) {
    LED_Controller::setOne(i, colors[color_num][0], colors[color_num][1], colors[color_num][2]); 

    if (i / 12 == 0)
      color_num = color_num++ % 12;
  }
}


// Rainbow -------------------------------------------------------------------------------------------------
void Patterns::Rainbow() {
  int colors[12][3] = {
    {255,0,0},
    {255,127,0},
    {255,255,0},
    {127,255,0},
    {0,255,0},
    {0,255,127},
    {0,255,255},
    {0,127,255},
    {0,0,255},
    {127,0,255},
    {255,0,255},
    {255,0,127}
  };
  int color_num = 0;

  for (int i = 0; i < LED_Controller::num_leds; i++) {
    color_num = color_num++ % 12;
    LED_Controller::lightOne(i, colors[color_num][0], colors[color_num][1], colors[color_num][2]);
  }

}

// Music Patterns ===============================================================================================
//===============================================================================================================

// Simple_Music ---------------------------------------------------------------------------------------------------------
void Patterns::Simple_Music() {
    LED_Controller::lightAll(r, g, b);
} 