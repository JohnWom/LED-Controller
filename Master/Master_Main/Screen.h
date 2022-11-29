#ifndef SCREEN.H
#define SCREEN .H

#include <DFRobot_RGBLCD1602.h>



class Screen
{
  public:
    // Default Parameterized Constructor
    Screen(Selectable* top, Selectable* bottom);

    // Executes Func on item 
    void exec_func();

    // returns next screen
    Screen* exec_screen();

    // Scroll Up
    void scrollUp();

    // Scroll Down
    void scrollDown();

  private:
    Selectable* top_item;
    Selectable* bottom_item;
    int cursor_pos;


};

#endif