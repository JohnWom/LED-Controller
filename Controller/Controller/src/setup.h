//
// Created by johnw on 7/30/2023.
//

#ifndef SETUP1_H
#define SETUP1_H

#endif //SETUP1_H

#include "Selectables/SelectableFactory.h"
#include "Selectables/FunctionSelectable.h"
#include "Selectables/CustomRGBSelectable.h"
#include "Selectables/ScreenSelectable.h"
#include "Screen.h"
#include "ScreenManager.h"
#include "ScreenManager.h"

/*
 * This is a collection of functions used for setting up the display Screens
 * Every Screen in declared in main, but should have its own function for building it
 * main also contains other definitions universal to the screens, such as preset colors
 *
 * Screen and Selectable creation must use dynamic memory!
*/


namespace setupScreens {
    ScreenManager* main();    // Entry Point for Screen Setup, returns ScreenManager object

    // Individual Screen Setup Functions
    void mainMenu(Screen*, Screen**, int, callback_t);

    // Helper Functions
    void buildScreen(Screen* screen, Selectable** selectables, int n_selectables);
    // links the list of selectables and adds the top 2 to the Screen

    void addSelectable(Selectable *head, Selectable *s);
    // Adds selectable s to selectable list headed by head
    // Adds the new selectable immediatly after head
}
