//
// Created by johnw on 7/8/2023.
//

#ifndef COMMAND_H
#define COMMAND_H

typedef struct Command {
    enum {COLOR, STATIC_P, MUSIC_P, NONE};
    int type;
    int value;
    unsigned short r;
    unsigned short g;
    unsigned short b;
} Command_t;

#endif //COMMAND_H
