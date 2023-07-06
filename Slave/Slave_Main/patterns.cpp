#include "patterns.h"

// Static Patterns =============================================================================================
//==============================================================================================================

//Solid Color --------------------------------------------------------------------------------------------------
void Patterns::Solid_Color() {
    LED_Controller::lightAll(r, g, b);
}

//Fishpole --------------------------------------------------------------------------------------------------
void Patterns::Color_Cycle() {

  int color_num = 0;
  while(1) {
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
    LED_Controller::lightAll(colors[color_num][0], colors[color_num][1], colors[color_num][2]);
    color_num = ++color_num % 12;
    delay(400);
   }
 
}


// Rainbow -------------------------------------------------------------------------------------------------
void Patterns::Rainbow() {
  int color_num = 0;
  while(1) {
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
  
  color_num++;
  for (int i = 0; i < LED_Controller::num_leds; i++) {

    color_num = ++color_num % 12;
    LED_Controller::lightOne(i, colors[color_num][0], colors[color_num][1], colors[color_num][2]);
  }
}


// Music Patterns ===============================================================================================
//===============================================================================================================

// Simple_Music ---------------------------------------------------------------------------------------------------------
void Patterns::Simple_Music() {
  int brightness;
    while(1) {
      int* bins = AudioProcessor::threeBand();
      int n = (5 * bins[0] + 2 * bins[1], 1*bins[2]);
      
      // Brightness Equation is based off of Natural Growth with Carrying Capacity
      brightness = (int) ceil(255 / (1 + 255*exp(-1*0.008*(n))));
      Serial.print("Volume: ");
      Serial.print(n);
      Serial.print("   Brightness: ");
      Serial.println(brightness);
      LED_Controller::setBrightness(brightness);
      LED_Controller::lightAll(r, g, b);
      free(bins);
  }
} 

void Patterns::Guitar() {
  int max = 0;
  LED_Controller::setBrightness(160);

  while(1) {
    int* bins = AudioProcessor::Live();

    max = Patterns::maxInArray(bins, 8);
    switch (max) {
      case 0:   // Red
        LED_Controller::lightAll(255, 0, 0);
        break;
      case 2:   // Orange
        LED_Controller::lightAll(200, 150, 0);
        break;
      case 3:   // Yellow
        LED_Controller::lightAll(200, 190, 0);
        break;
      case 4:   // Green
        LED_Controller::lightAll(0, 255, 0);
        break;
      case 5:   // Blue
        LED_Controller::lightAll(0, 0, 255);
        break;
      case 6:   // Indigo
        LED_Controller::lightAll(90, 5, 150);
        break;
      case 7:   // Violet
        LED_Controller::lightAll(255, 0, 255);
        break;
      default:  // Default Red
        LED_Controller::lightAll(255, 0, 0);
        break;

    }
  }
}





// Helper Functions =============================================================================================
//===============================================================================================================

int Patterns::maxInArray(int* bins, int size) {
  int max = 0;
  for(int i = 0; i < size; i++) {
      Serial.print("Bin ");
      Serial.print(i);
      Serial.print(": ");
      Serial.print(bins[i]);
      if(bins[i] > max)
        max = i;
    }
  Serial.println(' ');
  return max;
}


// Moving Average
/*
//  Update Moving average to last 1 minute
      count++;
      if (count % 10 == 0) {
        for (int i = 20; i>0; i--) 
          vals[i-1] = vals[i]; 
        vals[20] = n;

        for (int i = 0; i < 20; i++)
          average += vals[i];
        average /= 20;
        count = 0;
      }
      int average = 0;
  int vals[20] = {0};
*/

