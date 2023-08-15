//
// Created by johnw on 7/30/2023.
//

#ifndef SETUP1_H
#define SETUP1_H

#endif //SETUP1_H

#include "Selectables/SelectableFactory.h"
#include "Selectables/FunctionSelectable.h"
#include "Selectables/NumberSelectable.h"
#include "Selectables/ScreenSelectable.h"
#include "Screen.h"
#include "Operator.h"

void setupScreens() {

    // Screens
    Screen* Home = new Screen(nullptr, nullptr);
    Screen* Patterns = new Screen(nullptr, nullptr);
    Screen* Static = new Screen(nullptr, nullptr);
    Screen* Music = new Screen(nullptr, nullptr);
    Screen* Colors = new Screen(nullptr, nullptr);
    Screen* PrimaryColor = new Screen(nullptr, nullptr);
    Screen* SecondaryColor = new Screen(nullptr, nullptr);
    Screen* TertiaryColor = new Screen(nullptr, nullptr);
    Screen* CustomColor = new Screen(nullptr, nullptr);

    // Colors
    const int num_colors = 6;
    const int colors[num_colors][3] = {
            {200, 0, 0},
            {255, 140, 0},
            {0, 200, 0},
            {0, 0, 200},
            {60, 0, 255},
            {150, 0, 255}
    };

    const String colorNames[num_colors] = {
            "Red",
            "Orange",
            "Green",
            "Blue",
            "Indigo",
            "Violet"
    };




    }