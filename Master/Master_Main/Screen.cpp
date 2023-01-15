#include "Screen.h"




    // Default Parameterized Constructor
Screen::Screen(Selectable* top, Selectable* bottom) {
    top_item = top;
    bottom_item = bottom;
    cursor_pos = 0;
}

    // Scroll Up
int Screen::scrollUp() {
      // If cursor is on lower item, just move it up
      if (cusor_pos == 1) {
        cursor_pos = 0;
        return 0;
      } else {  // Otherwise Rotate Items
        bottom_item = top_item;
        top_item = top_item->prev();
        return 1;
      }
    }

int Screen::scrollDown() {
    // If cursor is on top item, just move it down
    if (cusor_pos == 0) {
      cursor_pos = 1;
      return 0;
    } else {  // Otherwise Rotate Items
      top_item = bottom_item;
      bottom_item = bottom_item->next();
      return 1;
  }
}



