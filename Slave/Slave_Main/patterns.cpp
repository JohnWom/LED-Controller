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
void Color_Cycle() {
  int pallet[7][3] = {{128,0,0},{255,100,0},{255,0,0},{0,128,0},{0,0,205},{75,0,130},{128,0,128}};
  int c = 0;

  for (int i = 0; i < 255; i++) {
    Serial.println(pallet[c][1]);
    pixels.setPixelColor(i, pallet[c][0], pallet[c][1], pallet[c][2]);
    c+= 1;
    if (c > 6) {c = 0;}
  }
  c += 1;
  pixels.show();
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