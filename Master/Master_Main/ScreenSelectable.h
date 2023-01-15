#ifndef SCREENSELECTABLE.H
#define SCREENSELECTABLE.H

#include "Screen.h"
#include "Selectables.h"

//forward declaration
class Screen;

//selectable for screens
class ScreenSelectable : public Selectable 
{
  public:
    ScreenSelectable(char* = "               ");

    Screen* nextScreen();

    void setScreen(Screen*);

  private:
    Screen* screen;
};

#endif