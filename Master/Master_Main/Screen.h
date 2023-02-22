#ifndef SCREEN.H
#define SCREEN.H

#include "types.h"

class Screen;
//===================== Selectable ======================
// Structure that holds menu items that user can see
// and choose from
//
// Functions as acyclic doubly-linked list to allow 
// users to scroll through items
//
// Also contains 15 character text to display for item
// including whitespace, as well as either a function
// that the item can execute or a new screen that it
// can point to. The selectable objects should only 
// be used to either move to a new screen or execute
// some kind of functionality.
//
// *** DO NOT USE BOTH A FUNCTION AND SCREEN PTR ***
//=======================================================


struct Selectable {
    Selectable* next;
    Selectable* prev;

    char* text;
    funcptr functpoint;
    Screen* next_screen;
};

//========================= Screen =========================
// Screen is a class that holds the two selectables
// that should be displayed on the screen at a given
// time. The starting items are given upon initialization.
// 
// The only logic contained here is the logic necessary
// to rotate through the items. These functions are 
// triggered by the operator class.
//===========================================================

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