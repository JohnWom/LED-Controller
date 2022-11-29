#include "Screen.h"




class Screen
{
  public:
    // Default Parameterized Constructor
    Screen(Selectable* top, Selectable* bottom) {
      top_item = top;
      bottom_item = bottom;
      cursor_pos = 0;
    }

    // Executes Func on item 
    void exec_func() {
      Selectable* current;
      // Set current to item cursor is on
      if (cursor_pos == 0) {
        current = top_item;
      } else {
        current = bottom_item;
      }
      if (current->funcpoint != NULL) {
        (current->*exec)();
      }
      
    }

    // returns next screen
    Screen* exec_screen(){
      Selectable* current;
      // Set current to item cursor is on
      if (cursor_pos == 0) {
        current = top_item;
      } else {
        current = bottom_item;
      }
      if (current->screen != NULL) {
        return current->screen;
      }
      
    } 

    // Scroll Up
    void scrollUp() {
      // If cursor is on lower item, just move it up
      if (cusor_pos == 1) {
        cursor_pos = 0;
        return;
      } else {  // Otherwise Rotate Items
        bottom_item = top_item;
        top_item = (top_item->*prev)();
      }
    }

    // Scroll Down
    void scrollDown() {
      // If cursor is on top item, just move it down
      if (cusor_pos == 0) {
        cursor_pos = 1;
        return;
      } else {  // Otherwise Rotate Items
        top_item = bottom_item;
        bottom_item = (bottom_item->*next)();
      }
    }
    }

  private:
    Selectable* top_item;
    Selectable* bottom_item;
    int cursor_pos;


}