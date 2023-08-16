//
// Created by johnw on 7/12/2023.
//

#ifndef SCREEN_H
#define SCREEN_H

#include "Selectables/SelectableInterface.h"
#include <Arduino.h>

/*
 * The Screen Class holds collections of Selectables that define
 * different screens. The Selectables are stored as a acyclic
 * linked list. There should be 1 Screen Object for each Screen.
*/

class Screen
{
public:
    Screen();
    Screen(Selectable*, Selectable*); // Top Selectable, Bottom Selectable

    void scrollUp();
    void scrollDown();

private:
    Selectable* topItem;
    Selectable* bottomItem;

public:
    // Getters & Setters
    Selectable *getTopItem() const;
    void setTopItem(Selectable *topItem);

    Selectable *getBottomItem() const;
    void setBottomItem(Selectable *bottomItem);
};


#endif //SCREEN_H
