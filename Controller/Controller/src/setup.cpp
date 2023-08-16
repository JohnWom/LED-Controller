//
// Created by johnw on 8/15/2023.
//

#include "setup.h"


ScreenManager* setupScreens::main() {
    // Screen Manager
    auto* SM = new ScreenManager();
    callback_t callback = (*SM).callback;

    // Screens
    auto* Home = new Screen();
    auto* Patterns = new Screen();
    auto* Static = new Screen();
    auto* Music = new Screen();
    auto* Colors = new Screen();
    auto* PrimaryColor = new Screen();
    auto* SecondaryColor = new Screen();
    auto* TertiaryColor = new Screen();
    auto* CustomColor = new Screen();

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

    setupScreens::mainMenu(Home, {Patterns, Static}, 2, callback);

}

void setupScreens::mainMenu(Screen *main, Screen **screens, int numScreens, callback_t c) {
    Selectable* selectables[numScreens+1]; // should be a selectable pointer for every screen + power off

    // Create Selectables for every Screen on main menu + power off
    selectables[0] = new   ScreenSelectable("Colors         ", screens[0], c);
    selectables[1] = new   ScreenSelectable("Patterns       ", screens[1], c);
    selectables[2] = new FunctionSelectable("Power Off     ", "C000000000");

    setupScreens::buildScreen(main, selectables, numScreens+1);
}


void setupScreens::buildScreen(Screen *screen, Selectable **selectables, int n_selectables) {
    for (int i=n_selectables-2; i>=0; i--) {
        addSelectable(selectables[n_selectables-1], selectables[i]);
    }
    screen->setTopItem(selectables[0]);
    screen->setBottomItem(selectables[1]);
}

void setupScreens::addSelectable(Selectable *head, Selectable *s) {
    // If no head, make the head
    if (head->getNext() == nullptr) {
        head->setNext(s);
        s->setPrev(head);
    }
    // otherwise insert at front
    else {
        Selectable* n = head->getNext();
        head->setNext(s);
        n->setPrev(s);
        s->setPrev(head);
        s->setNext(n);
    }
}