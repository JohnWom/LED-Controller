#ifndef OPERATOR.H
#define OPERATOR.H

#include "Screen.h"
#include <DFRobot_RGBLCD1602.h>

//Set up Joystick ====================================================
#define VRx A3     //X direction analog pin
#define VRy A2     //Y direction analog pin
#define SW  4      //Button/Click Digital Pin

class Operator
{
  public:

    Operator(Screen* = NULL, DFRobot_RGBLCD1602* = NULL);

    // Read Joystick
    void joystick_readings();
        // Draws text to Screen
    void draw();

    void draw_cursor();

  private:
    Screen* current_screen;
    
    DFRobot_RGBLCD1602* display; 

    int cursor_position;

    // Scrolls Up through screen options
    void Upscroll();

    // Scrolls Down through screen options
    void Downscroll();

    // Execute Command
    void click();

};

#endif