#ifndef FUNCTION.H
#define FUNCTION.H
#include "types.h"
#include <Arduino.h>
//===================== Codes ======================
// --- Functions that send codes to Slave Device ---
//    Core:
//         - Power On/Off: 0000000000
//
//--------------------------------------------------
//    Colors:
//         - Red:    C255000000
//         - Orange: C255135000
//         - Yellow: C255255000
//         - Green:  C000200000
//         - Blue:   C000000200
//         - Indigo: C060000255
//         - Violet: C140000255
//
//--------------------------------------------------
//     Patterns:
//         - Solid:    SP00000000
//         - Fishpole: SP00000001
//         - Rainbow:  SP00000002
//
//         - Simple M: MP00000000


// Core Functions ----------------------------------
void powerToggle();


// Color Functions ---------------------------------
void setColorRed();

void setColorOrange();

void setColorYellow();

void setColorGreen();

void setColorBlue();

void setColorIndigo();

void setColorViolet();


// Pattern Functions --------------------------------
void setSolid();

void setFishpole();

void setRainbow();



void setSimpleMusic();

// Pointers







#endif