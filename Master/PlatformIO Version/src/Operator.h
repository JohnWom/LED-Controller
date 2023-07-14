//
// Created by johnw on 7/12/2023.
//

#ifndef OPERATOR_H
#define OPERATOR_H

#include <DFRobot_RGBLCD1602.h>
#include "Selectables/SelectableInterface.h"
#include "Screen.h"

#define VRx A3
#define VRy A2
#define SW 4

class Operator
{
public:
    Operator(Screen*);

    void draw();
    void draw_cursor();

    void joystickRead();

    void callback(Screen*);
    DFRobot_RGBLCD1602 *getDisplay() const;

private:
    void upScroll();
    void downScroll();
    void rightScroll();
    void leftScroll();
    void click();

    Selectable* getCurrent();

    Screen* current_screen;
    DFRobot_RGBLCD1602* display;

    int cursor_position;
};


#endif //OPERATOR_H
