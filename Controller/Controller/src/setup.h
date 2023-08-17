//
// Created by johnw on 7/30/2023.
//

#ifndef SETUP1_H
#define SETUP1_H

#endif //SETUP1_H

#include "Selectables/FunctionSelectable.h"
#include "Selectables/CustomRGBSelectable.h"
#include "Selectables/ScreenSelectable.h"
#include "Screen.h"
#include "ScreenManager.h"
#include "ScreenManager.h"

/*
 * This is a collection of functions used for setting up the display screens
 * Every type of screen has it's own setup function. Common Screens (Preset & Custom Colors)
 * are used within other functions to make repetitive collections of screens
 * There are also some common helper functions to build a Screens
 *
 * Screen and Selectable creation must use dynamic memory!
*/


namespace setupScreens {
    enum ColorType {PRIMARY, SECONDARY, TERTIARY};
    ScreenManager* main();    // Entry Point for Screen Setup, returns ScreenManager object

    // Individual Screen Setup Functions
    void mainMenu(Screen* main, Screen* screens[], size_t, ScreenManager&);

    void PatternMenu(Screen *patternMenu, Screen *main, Screen *sPattern, Screen *mPattern, ScreenManager &sm);

    void StaticMenu(Screen *sMenu, Screen *back, ScreenManager &sm);

    void MusicMenu(Screen *mMenu, Screen *back, ScreenManager &sm);

    // Color Menus are build with several helping Functions
    // Each Function describes a type of screen
    void ColorMenus(Screen *cMenu, Screen *back, ScreenManager &sm);                    // Makes Menu for colors
    void ColorMenu(Screen *cMenu, Screen *back, int cOrder, ScreenManager &sm);         // Makes menu for each color
    void PresetColorMenu(Screen *pMenu, Screen *back, int cOrder, ScreenManager &sm);   // Makes Present Color Menu
    void CustomColorMenu(Screen *kMenu, Screen *back, int cOrder, ScreenManager &sm);   // Makes Custom Color Menu

    // Helper Functions
    void buildScreen(Screen* screen, Selectable* selectables[], size_t n_selectables);
    // links the list of selectables and adds the top 2 to the Screen

    void addSelectable(Selectable *head, Selectable *s);
    // Adds selectable s to selectable list headed by head
    // Adds the new selectable immediatly after head

    char* makeCommand(int r, int g, int b, int cOrder);
    // helper for PresetColorMenu builder
    // adds the cOrder into the command string
}
