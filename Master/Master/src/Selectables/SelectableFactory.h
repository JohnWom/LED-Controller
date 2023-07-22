//
// Created by johnw on 7/12/2023.
//

#ifndef SELECTABLEFACTORY_H
#define SELECTABLEFACTORY_H

#include "SelectableInterface.h"
#include "ScreenSelectable.h"
#include "NumberSelectable.h"
#include "FunctionSelectable.h"
#include <Arduino.h>


class SelectableFactory
{
public:
    SelectableFactory();

    enum {COLOR, STATIC, MUSIC, NUM, SCREEN};

    Selectable* make_selectable(String, int);

    static void addSelectable(Selectable*, Selectable*);

private:
    String fillText(String);

    int num_static;
    int num_music;

};


#endif //SELECTABLEFACTORY_H
