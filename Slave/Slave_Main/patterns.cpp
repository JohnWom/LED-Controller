#include "patterns.h"
Adafruit_NeoPixel pixels(NumLeds, LED_PIN, NEO_GRB + NEO_KHZ800);

extern int analyzed[8];

void Led_Setup() {
  pixels.begin();
  pixels.show();
  pixels.setBrightness(10);
}

// Static Patterns =============================================================================================
//==============================================================================================================

//Solid Color --------------------------------------------------------------------------------------------------
void Solid_Color(int r, int g, int b) {
  for (int i = 0; i < NumLeds; i++) {
    pixels.setPixelColor(i, r, g, b); 
  }
  pixels.show();
}

// Color Cycle -------------------------------------------------------------------------------------------------
void Color_Cycle(int r, int g, int b) {
  //Solid_Color(r, g, b);
  for (int i = 1; i < 255; i + 5) {
    pixels.setBrightness(i);
    delay(1);
  }
  
}

// Music Patterns ===============================================================================================
//===============================================================================================================

// Bass ---------------------------------------------------------------------------------------------------------
void Bass(int r, int g, int b) {
  for (int i = 0; i < NumLeds; i++) {
    pixels.setPixelColor(i, r, g, b);
  }
  pixels.show();
  //int avg_binv = (analyzed_audio[0] + analyzed_audio[1]) / 2;
  int m = round(0.085 * analyzed[0]);
  if (m > 255) {m = 255;} //Makes sure it doesn't go over max
  pixels.setBrightness(m);
}