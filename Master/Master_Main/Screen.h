#ifndef SCREEN.H
#define SCREEN .H

#include <DFRobot_RGBLCD1602.h>
#include "Selectables.h"

//Set up Joystick ====================================================
const VRx = A3;     //X direction analog pin
const VRy = A2;     //Y direction analog pin
const SW = 4;      //Button/Click Digital Pin


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



class Operator
{
  public:
    // Draws text to Screen
    void draw();

    // Scrolls Up through screen options
    void Upscroll();

    // Scrolls Down through screen options
    void Downscroll();

    // Execute Command
    void click();

    // Read Joystick
    void joystick_readings();

  private:
    Screen* current_screen;

}
#endif