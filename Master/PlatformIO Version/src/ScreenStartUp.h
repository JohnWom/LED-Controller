//
// Created by johnw on 7/12/2023.
//

#ifndef SCREENSTARTUP_H
#define SCREENSTARTUP_H

#include "Selectables/SelectableFactory.h"
#include "Selectables/ScreenSelectable.h"
#include "Selectables/FunctionSelectable.h"
#include "Selectables/NumberSelectable.h"
#include "Screen.h"


SelectableFactory* factory = new SelectableFactory();

//================[ Make Func Selectables ]================
// Colors
FunctionSelectable* red = new FunctionSelectable("Red", factory->createCommand(Command::COLOR, 0,255,255));
FunctionSelectable* orange = new FunctionSelectable("Orange", factory->createCommand(Command::COLOR, 8000,255,200));
FunctionSelectable* green = new FunctionSelectable("Green", factory->createCommand(Command::COLOR, 21845,255,255));
FunctionSelectable* blue = new FunctionSelectable("Blue", factory->createCommand(Command::COLOR, 43691,255,255));
FunctionSelectable* purple = new FunctionSelectable("Purple", factory->createCommand(Command::COLOR, 49152,255,255));

// Static
FunctionSelectable* static0 = new FunctionSelectable("Solid Color", factory->createCommand(Command::STATIC_P, 0,0,0));
FunctionSelectable* static1 = new FunctionSelectable("Party 1", factory->createCommand(Command::STATIC_P, 0,0,0));
FunctionSelectable* static2 = new FunctionSelectable("Party 2", factory->createCommand(Command::STATIC_P, 0,0,0));
FunctionSelectable* static3 = new FunctionSelectable("Party 3", factory->createCommand(Command::STATIC_P, 0,0,0));
FunctionSelectable* static4 = new FunctionSelectable("Rainbow", factory->createCommand(Command::STATIC_P, 0,0,0));
FunctionSelectable* static5 = new FunctionSelectable("Tri-Color", factory->createCommand(Command::STATIC_P, 0,0,0));

// Music
FunctionSelectable* music1 = new FunctionSelectable("Music 1", factory->createCommand(Command::MUSIC_P, 0,0,0));
FunctionSelectable* music2 = new FunctionSelectable("Music 2", factory->createCommand(Command::MUSIC_P, 0,0,0));

//================[ Make Screen Selectables ]================

//================[ Make Number Selectables ]================
NumberSelectable* chooseHue = new NumberSelectable("Change Hue", 0, 65535, NumberSelectable::HUE);
NumberSelectable* chooseSat = new NumberSelectable("Change Sat", 0, 255, NumberSelectable::SAT);
NumberSelectable* chooseBright = new NumberSelectable("Change Bright", 0, 255, NumberSelectable::V);

#endif //SCREENSTARTUP_H
