#ifndef SCREEN.H
#define SCREEN.H

#include "types.h"

class Screen;

struct Selectable {
    Selectable* next;
    Selectable* prev;

    char* text;
    funcptr functpoint;
    Screen* next_screen;
};

class Screen
{
  public:
    // Default Parameterized Constructor
    Screen(Selectable*, Selectable*);

    // Scroll Up
    void scrollUp();

    // Scroll Down
    void scrollDown();

  private:
    Selectable* top_item;
    Selectable* bottom_item;

  friend class Operator;
};

#endif