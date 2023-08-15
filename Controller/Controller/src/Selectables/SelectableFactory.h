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
    enum {COLOR, STATIC, MUSIC, NUM, SCREEN};

    void buildScreen(Screen* , Selectable*, int);

    Selectable* colorFunction(String, int, const int color[3]);

    void addSelectable(Selectable &, Selectable &);

private:
    String fillText(String);

    int num_static;
    int num_music;

};


#endif //SELECTABLEFACTORY_H
