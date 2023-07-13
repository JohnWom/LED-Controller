//
// Created by johnw on 7/12/2023.
//

#ifndef PLATFORMIO_VERSION_SCREENSELECTABLE_H
#define PLATFORMIO_VERSION_SCREENSELECTABLE_H

#include "SelectableInterface.h"
#include "../Screen.h"

class Screen;

class ScreenSelectable: public Selectable
{
public:
    ScreenSelectable(char*, Screen*, void (*c)(Screen*), Selectable*, Selectable*);

    void execute() override;

private:
    Screen* nextScreen;
    void (*callback)(Screen*);
};


#endif //SCREENSELECTABLE_H
