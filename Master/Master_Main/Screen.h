#ifndef SCREEN.H
#define SCREEN .H

#include "ScreenSelectable.h"
#include "FuncSelectable.h"



class Screen
{
  public:
    // Default Parameterized Constructor
    Screen(Selectable*, Selectable*);

    // Scroll Up
    int scrollUp();

    // Scroll Down
    int scrollDown();

  private:
    Selectable* top_item;
    Selectable* bottom_item;
    int cursor_pos;

};

#endif