#ifndef PATTERNS
#define PATTERNS

#include "AudioProcessor.h"
#include "LED_Controller.h"

class Patterns {
  public:

    Patterns(LED_Controller*, AudioProcessor*);

    //Static Pattern Functions ============================================================================

    void Solid_Color(); //Fills the Strip with a solid Color

    void Color_Cycle(); //Cylces Through Colors

    void Rainbow(); //Plays Moving Rainbow Threw Color

    //Music Pattern Functions =============================================================================

    void Simple_Music(); // Sets LEDS to go with Bass of song

  private:
    LED_Controller* leds;
    AudioProcessor* ap;

    int r;

    int g;

    int b;

  friend class Operator;
};

#endif
