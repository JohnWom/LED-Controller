//
// Created by johnw on 8/15/2023.
//

#include "setup.h"


ScreenManager* setupScreens::main() {
    // Screen Manager
    auto* SM = new ScreenManager();

    // Screens
    auto* Home = new Screen();
    auto* Patterns = new Screen();
    auto* Static = new Screen();
    auto* Music = new Screen();
    auto* Colors = new Screen();

    // Build Main Screen
    Screen *mainScreens[2] = {Colors, Patterns};
    setupScreens::mainMenu(Home, mainScreens, 2, *SM);

    // Build Patterns Screens
    setupScreens::PatternMenu(Patterns, Home, Static, Music, *SM);
    setupScreens::StaticMenu(Static, Patterns, *SM);
    setupScreens::MusicMenu(Music, Patterns, *SM);

    //Build Color Screens
    setupScreens::ColorMenus(Colors, Home, *SM);

    SM->setScreen(Home);
    return SM;
}

void setupScreens::mainMenu(Screen *main, Screen *screens[], size_t numScreens, ScreenManager &sm) {
    Selectable* selectables[numScreens+1]; // should be a selectable pointer for every screen + power off

    // Create Selectables for every Screen on main menu + power off
    selectables[0] = new   ScreenSelectable("Colors         ", screens[0], sm);
    selectables[1] = new   ScreenSelectable("Patterns       ", screens[1], sm);
    selectables[2] = new FunctionSelectable("Power Off     ", "C000000000");

    setupScreens::buildScreen(main, selectables, numScreens+1);
}

void setupScreens::PatternMenu(Screen *patternMenu, Screen *main, Screen *sPattern, Screen *mPattern, ScreenManager &sm) {
    Selectable* selectables[3];
    selectables[0] = new ScreenSelectable("back           ", main, sm);
    selectables[1] = new ScreenSelectable("Static Patterns", sPattern, sm);
    selectables[2] = new ScreenSelectable("Music Patterns ", mPattern, sm);

    setupScreens::buildScreen(patternMenu, selectables, 3);
}

void setupScreens::StaticMenu(Screen *sMenu, Screen *back, ScreenManager &sm) {
    const size_t numStaticPatterns = 8;
    Selectable* selectables[numStaticPatterns + 1];

    selectables[0] = new   ScreenSelectable("back           ", back, sm);
    selectables[1] = new FunctionSelectable("Solid Color    ", "SP00000000");
    selectables[2] = new FunctionSelectable("Party 1        ", "SP00000001");
    selectables[3] = new FunctionSelectable("Party 2        ", "SP00000002");
    selectables[4] = new FunctionSelectable("Party 3        ", "SP00000003");
    selectables[5] = new FunctionSelectable("Rainbow        ", "SP00000004");
    selectables[6] = new FunctionSelectable("Three Color    ", "SP00000005");
    selectables[7] = new FunctionSelectable("Ocean          ", "SP00000006");
    selectables[8] = new FunctionSelectable("Insanity       ", "SP00000007");

    setupScreens::buildScreen(sMenu, selectables, numStaticPatterns+1);
}

void setupScreens::MusicMenu(Screen *mMenu, Screen *back, ScreenManager &sm) {
    const size_t numMusicPatterns = 2;
    Selectable* selectables[numMusicPatterns + 1];

    selectables[0] = new   ScreenSelectable("back           ", back, sm);
    selectables[1] = new FunctionSelectable("Music Pattern 1", "SP00000000");
    selectables[2] = new FunctionSelectable("Music Pattern 2", "SP00000001");

    setupScreens::buildScreen(mMenu, selectables, numMusicPatterns + 1);
}

void setupScreens::ColorMenus(Screen *cMenu, Screen *back, ScreenManager &sm) {
    const int num_colors = 3;
    Selectable* selectables[num_colors + 1];

    // Make Color Sub Menus
    auto* Primary = new Screen();
    auto* Secondary = new Screen();
    auto* Tertiary = new Screen();

    setupScreens::ColorMenu(Primary, cMenu, PRIMARY, sm);
    setupScreens::ColorMenu(Secondary, cMenu, SECONDARY, sm);
    setupScreens::ColorMenu(Tertiary, cMenu, TERTIARY, sm);

    // Set up Menu to Choose Primary, Secondary, ... color
    selectables[0] = new ScreenSelectable("back           ", back, sm);
    selectables[1] = new ScreenSelectable("Primary        ", Primary, sm);
    selectables[2] = new ScreenSelectable("Secondary      ", Secondary, sm);
    selectables[3] = new ScreenSelectable("Tertiary       ", Tertiary, sm);

    buildScreen(cMenu, selectables, num_colors + 1);
}

void setupScreens::ColorMenu(Screen *cMenu, Screen *back, int cOrder, ScreenManager &sm) {
    auto* presetColors = new Screen();
    auto* customColors = new Screen();

    // Build the Present and Custom Color Screens
    PresetColorMenu(presetColors, cMenu, cOrder, sm);
    CustomColorMenu(customColors, cMenu, cOrder, sm);

    // Build the Color Menu
    Selectable* selectables[3];
    selectables[0] = new ScreenSelectable("back           ", back, sm);
    selectables[1] = new ScreenSelectable("Preset Color   ", presetColors, sm);
    selectables[2] = new ScreenSelectable("Custom Color   ", customColors, sm);

    buildScreen(cMenu, selectables, 3);
}

void setupScreens::PresetColorMenu(Screen *pMenu, Screen *back, int cOrder, ScreenManager &sm) {
    const int nColors = 6;
    Selectable* selectables[nColors + 1];

    selectables[0] = new   ScreenSelectable("back            ", back, sm);
    selectables[1] = new FunctionSelectable("Red             ", setupScreens::makeCommand(200, 0, 0, cOrder));
    selectables[2] = new FunctionSelectable("Orange          ", setupScreens::makeCommand(255, 140, 0, cOrder));
    selectables[3] = new FunctionSelectable("Green           ", setupScreens::makeCommand(0, 200, 0, cOrder));
    selectables[4] = new FunctionSelectable("Blue            ", setupScreens::makeCommand(0, 0, 200, cOrder));
    selectables[5] = new FunctionSelectable("Indigo          ", setupScreens::makeCommand(6, 0, 255, cOrder));
    selectables[6] = new FunctionSelectable("Violet          ", setupScreens::makeCommand(140, 0, 255, cOrder));

    buildScreen(pMenu, selectables, nColors + 1);
}

void setupScreens::CustomColorMenu(Screen *kMenu, Screen *back, int cOrder, ScreenManager &sm) {
    Selectable* selectables[4];

    selectables[0] = new    ScreenSelectable("back           ", back, sm);
    selectables[1] = new CustomRGBSelectable("Set R          ", 0, 255, CustomRGBSelectable::R, cOrder);
    selectables[2] = new CustomRGBSelectable("Set G          ", 0, 255, CustomRGBSelectable::G, cOrder);
    selectables[3] = new CustomRGBSelectable("Set B          ", 0, 255, CustomRGBSelectable::B, cOrder);

    setupScreens::buildScreen(kMenu, selectables, 4);
}



void setupScreens::buildScreen(Screen *screen, Selectable *selectables[], size_t n_selectables) {
    // Link Selectables in order of array
    for (size_t i=n_selectables-1; i>0; i--) {
        addSelectable(selectables[0], selectables[i]);
    }

    // Put first two selectables as main point in screen
    screen->setTopItem(selectables[0]);
    screen->setBottomItem(selectables[1]);
}

void setupScreens::addSelectable(Selectable *head, Selectable *s) {
    // If no head, make the head
    if (head->getNext() == nullptr) {
        head->setNext(s);
        s->setPrev(head);
    }
    // otherwise insert at immediately after the head
    else {
        Selectable* n = head->getNext();
        head->setNext(s);
        n->setPrev(s);
        s->setPrev(head);
        s->setNext(n);
    }
}

char* setupScreens::makeCommand(int r, int g, int b, int cOrder) {
    String cmd = "C";
    cmd += String(cOrder);

    String colors[3] = {String(r), String(g), String(b)};
    for (const auto & color : colors) {
        switch (color.length()) {
            case 1:
                cmd += "0";
                cmd += "0";
                cmd += String(color);
                break;
            case 2:
                cmd += "0";
                cmd += String(color);
                break;
            case 3:
                cmd += String(color);
                break;
        }
    }

    char t[11];
    cmd.toCharArray(t, 11);
    return t;
}