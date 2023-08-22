//
// Created by johnw on 7/8/2023.
//

#ifndef COMMAND_H
#define COMMAND_H

#include <FastLED.h>

/*
 * Struct to pass Commands between Serial Reader class and
 * Operator class
*/

typedef struct Command {
    enum {COLOR, STATIC_P, MUSIC_P, NONE};
    int type;
    int value;
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Command_t;

#endif //COMMAND_H
