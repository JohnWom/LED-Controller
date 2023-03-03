#ifndef PATTERNS
#define PATTERNS

#include "AudioProcessor.h"
#include "LED_Controller.h"

// Static Class Patterns 
// More a formality for holding patterns under a single space. 
// Must be static to run on seperate thread. Pattern control is excuted under Operator class
// Pulls LED controler from LED_Controller class and Audio Reading from AudioProcessor class

class Patterns {
  public:

    //Static Pattern Functions ============================================================================

    static void Solid_Color(); //Fills the Strip with a solid Color

    static void Color_Cycle(); //Cylces Through Colors

    static void Rainbow(); //Plays Moving Rainbow Threw Color

    //Music Pattern Functions =============================================================================

    static void Simple_Music(); // Sets LEDS to go with Bass of song

    static int r;

    static int g;

    static int b;

};

#endif
