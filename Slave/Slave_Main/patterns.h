#ifndef PATTERNS
#define PATTERNS
//This contains all pattern functions
#include "audio-processing.h"
#include <Adafruit_NeoPixel.h>
#define LED_PIN D0
#define NumLeds 300

void Led_Setup(); //Functions for Setting up Strip

//Static Pattern Functions ============================================================================

void Solid_Color(int,int,int); //Fills the Strip with a solid Color

void Color_Cycle(int, int, int); //Cylces Through Colors

//Music Pattern Functions =============================================================================

void Bass(int, int, int); // Sets LEDS to go with Bass of song

#endif
