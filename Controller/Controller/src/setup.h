//
// Created by johnw on 7/21/2023.
//

#ifndef SETUP_H
#define SETUP_H

#include "Selectables/SelectableFactory.h"
#include "Selectables/FunctionSelectable.h"
#include "Selectables/NumberSelectable.h"
#include "Selectables/ScreenSelectable.h"
#include "Screen.h"
#include "Operator.h"


Screen* Home = new Screen(nullptr, nullptr);
Screen* Patterns = new Screen(nullptr, nullptr);
Screen* Static = new Screen(nullptr, nullptr);
Screen* Music = new Screen(nullptr, nullptr);
Screen* Color = new Screen(nullptr, nullptr);
Screen* CustomColor = new Screen(nullptr, nullptr);

Operator* Op = new Operator(Home);

// Home Screen Selectables
Selectable* toColors = new ScreenSelectable("Colors         ", Color, Op);
Selectable* toPatterns = new ScreenSelectable("Patterns       ",Patterns, Op);
Selectable* powerOff = new FunctionSelectable("Power off      ", "C000000000");
// Color Screen Selectables
Selectable* backColors = new ScreenSelectable("back           ", Home, Op);
Selectable* toCustomColors = new ScreenSelectable("Custom Color   ", CustomColor, Op);
Selectable* red =    new FunctionSelectable("Red            ", "C200000000");
Selectable* orange = new FunctionSelectable("Orange         ", "C255140000");
Selectable* green =  new FunctionSelectable("Green          ", "C000200000");
Selectable* blue =   new FunctionSelectable("Blue           ", "C000000200");
Selectable* indigo = new FunctionSelectable("Indigo         ", "C060000255");
Selectable* violet = new FunctionSelectable("Violet         ", "C140000255");

// Custom Colors Selectables
Selectable* backCustomColors = new ScreenSelectable("back           ", Color, Op);
Selectable* setR = new NumberSelectable("Set R          ", 0, 255, NumberSelectable::R);
Selectable* setG = new NumberSelectable("Set G          ", 0, 255, NumberSelectable::G);
Selectable* setB = new NumberSelectable("Set B          ", 0, 255, NumberSelectable::B);

// Patterns selectables
Selectable* backPattern = new ScreenSelectable("back           ", Home, Op);
Selectable* toStatic = new ScreenSelectable("Static Patterns", Static, Op);
Selectable* toMusic =  new ScreenSelectable("Music Patterns ", Music, Op);

// Music Selectables
Selectable* backMusic = new ScreenSelectable("back           ", Patterns, Op);
Selectable* mp1 = new FunctionSelectable("Music Pattern 1", "MP00000000");
Selectable* mp2 = new FunctionSelectable("Music Pattern 2", "MP00000001");


// Static Selectables
Selectable* backStatic = new ScreenSelectable("back           ", Patterns, Op);
Selectable* solidColor =    new FunctionSelectable("Solid Color    ", "SP00000000");
Selectable* sp1 =           new FunctionSelectable("Party 1        ", "SP00000001");
Selectable* sp2 =           new FunctionSelectable("Party 2        ", "SP00000002");
Selectable* sp3 =           new FunctionSelectable("Party 3        ", "SP00000003");
Selectable* rainbow =       new FunctionSelectable("Rainbow        ", "SP00000004");
Selectable* triColor =      new FunctionSelectable("Three Color    ", "SP00000005");
Selectable* ocean =         new FunctionSelectable("Ocean          ", "SP00000006");

void connect_selectables() {
    // Home Screen Selectables
    SelectableFactory::addSelectable(toColors, powerOff);
    SelectableFactory::addSelectable(toColors, toPatterns);
    Home->setTopItem(toColors);
    Home->setBottomItem(toPatterns);

    // Color Screen Selectables
    SelectableFactory::addSelectable(backColors, violet);
    SelectableFactory::addSelectable(backColors, indigo);
    SelectableFactory::addSelectable(backColors, blue);
    SelectableFactory::addSelectable(backColors, green);
    SelectableFactory::addSelectable(backColors, orange);
    SelectableFactory::addSelectable(backColors, red);
    SelectableFactory::addSelectable(backColors, toCustomColors);
    Color->setTopItem(backColors);
    Color->setBottomItem(toCustomColors);

    // Custom Color Selectables
    SelectableFactory::addSelectable(backCustomColors, setB);
    SelectableFactory::addSelectable(backCustomColors, setG);
    SelectableFactory::addSelectable(backCustomColors, setR);
    CustomColor->setTopItem(backCustomColors);
    CustomColor->setBottomItem(setR);

    // Patterns Selectables
    SelectableFactory::addSelectable(backPattern, toMusic);
    SelectableFactory::addSelectable(backPattern, toStatic);
    Patterns->setTopItem(backPattern);
    Patterns->setBottomItem(toStatic);

    // Music Selectables
    SelectableFactory::addSelectable(backMusic, mp2);
    SelectableFactory::addSelectable(backMusic, mp1);
    Music->setTopItem(backMusic);
    Music->setBottomItem(mp1);

    // Static Selectables
    SelectableFactory::addSelectable(backStatic, ocean);
    SelectableFactory::addSelectable(backStatic, triColor);
    SelectableFactory::addSelectable(backStatic, rainbow);
    SelectableFactory::addSelectable(backStatic, sp3);
    SelectableFactory::addSelectable(backStatic, sp2);
    SelectableFactory::addSelectable(backStatic, sp1);
    SelectableFactory::addSelectable(backStatic, solidColor);
    Static->setTopItem(backStatic);
    Static->setBottomItem(solidColor);
}






#endif //SETUP_H
