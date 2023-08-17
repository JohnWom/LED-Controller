//
// Created by johnw on 7/12/2023.
//

#ifndef SCREENSELECTABLE_H
#define SCREENSELECTABLE_H

#include "SelectableInterface.h"
#include "../Screen.h"
#include "../ScreenManager.h"
/*
 * This Selectable is used for changing Screens.
 * On execute, it uses a callback to change the screen
*/



class ScreenSelectable: public Selectable
{
public:
    explicit ScreenSelectable(char*, ScreenManager&);
    ScreenSelectable(char*, Screen*, ScreenManager&);

    void execute() override;

private:
    Screen* nextScreen;
    ScreenManager &screenManager;

public:
    // Getters & Setters
    void setNextScreen(Screen *s);
    Screen *getNextScreen() const;
};


#endif //SCREENSELECTABLE_H
