//
// Created by johnw on 7/12/2023.
//

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <DFRobot_RGBLCD1602.h>
#include "Selectables/SelectableInterface.h"
#include "Screen.h"

#define VRx A3  // Pin for joystick X direction
#define VRy A2  // Pin for joystick Y direction
#define SW 4    // Pin for joystick button

/*
 * ScreenManager runs Controller Chip. It handles the user input
 * and how the display reacts to it. It also carries the user actions
 * to Selectables on clicks and r/l scrolling.
 *
 * This class should be a Singleton, only one should exist
 * Since this code is fairly small, the actual Singleton is not implemented
*/

class ScreenManager
{
public:
    ScreenManager();
    ScreenManager(Screen*);

    void draw();        // Should only be called in setup
    void draw_cursor(); // Should only be called in setup

    void joystickRead();    // Main entry point to the class

    void callback(Screen*);

private:
    void upScroll();
    void downScroll();
    void rightScroll();
    void leftScroll();
    void click();

    Selectable* getCurrent();

    Screen* currentScreen;
    DFRobot_RGBLCD1602* display;

    int cursorPosition;

public:
    // Getters & Setters
    DFRobot_RGBLCD1602 *getDisplay() const;

    void setScreen(Screen*);
};


#endif //SCREENMANAGER_H
