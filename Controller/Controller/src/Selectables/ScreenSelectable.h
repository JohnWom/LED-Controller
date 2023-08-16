//
// Created by johnw on 7/12/2023.
//

#ifndef SCREENSELECTABLE_H
#define SCREENSELECTABLE_H

#include "SelectableInterface.h"
#include "../Screen.h"

/*
 * This Selectable is used for changing Screens.
 * On execute, it uses a callback to change the screen
*/

// callback to set the new screen
typedef void (*callback_t)(Screen*);

class ScreenSelectable: public Selectable
{
public:
    explicit ScreenSelectable(char*);
    ScreenSelectable(char*, Screen*, callback_t);

    void execute() override;

private:
    Screen* nextScreen;
    callback_t callback;

public:
    // Getters & Setters
    void setCallback(callback_t);

    void setNextScreen(Screen *s);
    Screen *getNextScreen() const;
};


#endif //SCREENSELECTABLE_H
