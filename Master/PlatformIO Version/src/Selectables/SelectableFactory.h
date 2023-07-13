//
// Created by johnw on 7/12/2023.
//

#ifndef SELECTABLEFACTORY_H
#define SELECTABLEFACTORY_H

#include "SelectableInterface.h"
#include <Arduino.h>

typedef struct Command {
    enum {COLOR, STATIC_P, MUSIC_P, NONE};
    int type;
    int value;
    unsigned short r;
    unsigned short g;
    unsigned short b;
} Command_t;

class SelectableFactory
{
public:
    SelectableFactory();

    void addSelectable(Selectable*, Selectable*);

    String createCommand(int, int, int, int);

    String fillText(char* msg);

private:
    int num_static;
    int num_music;
};


#endif //SELECTABLEFACTORY_H
