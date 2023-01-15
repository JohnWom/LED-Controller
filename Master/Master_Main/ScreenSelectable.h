#ifndef SCREENSELECTABLE.H
#define SCREENSELECTABLE.H

#include "Selectables.h"
#include "Screen.h"

//selectable for screens
class ScreenSelectable:Selectable 
{
  public:
    ScreenSelectable(char, Selectable*, Selectable*, Screen*);

    Screen* nextScreen();

    void setScreen(Screen*);

  private:
    Screen* screen;
};

#endif