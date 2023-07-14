//
// Created by johnw on 7/12/2023.
//

#ifndef PLATFORMIO_VERSION_SCREENSELECTABLE_H
#define PLATFORMIO_VERSION_SCREENSELECTABLE_H

#include "SelectableInterface.h"
#include "../Screen.h"
#include "Operator.h"

class ScreenSelectable: public Selectable
{
public:
    ScreenSelectable(char*, Screen*, Operator*);

    void execute() override;

    Screen *getNextScreen() const;

    void setNextScreen(Screen *s);

private:
    Screen* nextScreen;
    Operator* op;
public:
    Operator *getOp() const;

    void setOp(Operator *op);
};


#endif //SCREENSELECTABLE_H
