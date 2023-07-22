//
// Created by johnw on 7/12/2023.
//

#ifndef SCREEN_H
#define SCREEN_H

#include "Selectables/SelectableInterface.h"
#include <Arduino.h>

class Screen
{
public:
    Screen(Selectable*, Selectable*);

    void scrollUp();
    void scrollDown();


    Selectable *getTopItem() const;
    void setTopItem(Selectable *topItem);
    Selectable *getBottomItem() const;
    void setBottomItem(Selectable *bottomItem);

private:
    Selectable* topItem;
    Selectable* bottomItem;
};


#endif //SCREEN_H
