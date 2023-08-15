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
Screen* Colors = new Screen(nullptr, nullptr);
Screen* PrimaryColor = new Screen(nullptr, nullptr);
Screen* SecondaryColor = new Screen(nullptr, nullptr);
Screen* TertiaryColor = new Screen(nullptr, nullptr);
Screen* CustomColor = new Screen(nullptr, nullptr);

Operator* Op = new Operator(Home);

// Home Screen Selectables
Selectable* toColors = new ScreenSelectable("Colors         ", PrimaryColor, Op);
Selectable* toPatterns = new ScreenSelectable("Patterns       ",Patterns, Op);
Selectable* powerOff = new FunctionSelectable("Power off      ", "C000000000");

// Color Screen Selectables
Selectable* backColor =         new ScreenSelectable("back           ", Home, Op);
Selectable* toPrimaryColor =    new ScreenSelectable("Colors         ", PrimaryColor, Op);
Selectable* toSecondaryColor =  new ScreenSelectable("Colors         ", SecondaryColor, Op);
Selectable* toTertiaryColor =   new ScreenSelectable("Colors         ", TertiaryColor, Op);

// PrimaryColor Screen Selectables
Selectable* backPrimaryColor = new ScreenSelectable("back           ", Colors, Op);
Selectable* toCustomColors = new ScreenSelectable("Custom PrimaryColor   ", CustomColor, Op);
Selectable* pred =    new FunctionSelectable("Red            ", "C0200000000");
Selectable* porange = new FunctionSelectable("Orange         ", "C0255140000");
Selectable* pgreen =  new FunctionSelectable("Green          ", "C0000200000");
Selectable* pblue =   new FunctionSelectable("Blue           ", "C0000000200");
Selectable* pindigo = new FunctionSelectable("Indigo         ", "C0060000255");
Selectable* pviolet = new FunctionSelectable("Violet         ", "C0140000255");

// SecondaryColor Screen Selectables
Selectable* backSecondaryColor =    new ScreenSelectable("back           ", Colors, Op);
Selectable* toCustomColors =        new ScreenSelectable("Custom PrimaryColor   ", CustomColor, Op);
Selectable* sred =    new FunctionSelectable("Red            ", "C0200000000");
Selectable* sorange = new FunctionSelectable("Orange         ", "C0255140000");
Selectable* sgreen =  new FunctionSelectable("Green          ", "C0000200000");
Selectable* sblue =   new FunctionSelectable("Blue           ", "C0000000200");
Selectable* sindigo = new FunctionSelectable("Indigo         ", "C0060000255");
Selectable* sviolet = new FunctionSelectable("Violet         ", "C0140000255");

// Custom Colors Selectables
Selectable* backCustomColors = new ScreenSelectable("back           ", PrimaryColor, Op);
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
Selectable* solidColor =    new FunctionSelectable("Solid PrimaryColor    ", "SP00000000");
Selectable* sp1 =           new FunctionSelectable("Party 1        ", "SP00000001");
Selectable* sp2 =           new FunctionSelectable("Party 2        ", "SP00000002");
Selectable* sp3 =           new FunctionSelectable("Party 3        ", "SP00000003");
Selectable* rainbow =       new FunctionSelectable("Rainbow        ", "SP00000004");
Selectable* triColor =      new FunctionSelectable("Three PrimaryColor    ", "SP00000005");
Selectable* ocean =         new FunctionSelectable("Ocean          ", "SP00000006");
Selectable* insanity =      new FunctionSelectable("Insanity       ", "SP00000007");

void connect_selectables() {
    // Home Screen Selectables
    SelectableFactory::addSelectable(toColors, powerOff);
    SelectableFactory::addSelectable(toColors, toPatterns);
    Home->setTopItem(toColors);
    Home->setBottomItem(toPatterns);

    // PrimaryColor Screen Selectables
    SelectableFactory::addSelectable(backPrimaryColor, violet);
    SelectableFactory::addSelectable(backPrimaryColor, indigo);
    SelectableFactory::addSelectable(backPrimaryColor, blue);
    SelectableFactory::addSelectable(backPrimaryColor, green);
    SelectableFactory::addSelectable(backPrimaryColor, orange);
    SelectableFactory::addSelectable(backPrimaryColor, red);
    SelectableFactory::addSelectable(backPrimaryColor, toCustomColors);
    PrimaryColor->setTopItem(backPrimaryColor);
    PrimaryColor->setBottomItem(toCustomColors);

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
    SelectableFactory::addSelectable(backStatic, insanity);
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
