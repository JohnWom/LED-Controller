#ifndef PATTERNS
#define PATTERNS

#include "AudioProcessor.h"
#include "LED_Controller.h"

class Patterns {
  public:

    Patterns(LED_Controller*, AudioProcessor*);

    //Static Pattern Functions ============================================================================

    static void Solid_Color(); //Fills the Strip with a solid Color

    static void Color_Cycle(); //Cylces Through Colors

    static void Rainbow(); //Plays Moving Rainbow Threw Color

    //Music Pattern Functions =============================================================================

    static void Simple_Music(); // Sets LEDS to go with Bass of song

    static int r;

    static int g;

    static int b;

  friend class Operator;
};

#endif
