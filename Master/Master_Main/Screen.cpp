#include "Screen.h"

    // Default Parameterized Constructor
Screen::Screen(Selectable* top, Selectable* bottom) {
    top_item = top;
    bottom_item = bottom;
}

    // Scroll Up
void Screen::scrollUp() { 
    bottom_item = top_item;
    top_item = top_item->prev; 
}

void Screen::scrollDown() {
      top_item = bottom_item;
      bottom_item = bottom_item->next;
}



