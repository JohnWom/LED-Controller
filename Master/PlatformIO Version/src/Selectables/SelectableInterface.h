//
// Created by johnw on 7/12/2023.
//

#ifndef SELECTABLEINTERFACE_H
#define SELECTABLEINTERFACE_H

#include <Arduino.h>

class Selectable
{
public:
    Selectable(String, Selectable*, Selectable*);
    virtual void execute()=0;

    // Special Commands for in-selectable controls
    // Enables joystick input -> Selectable
    virtual void rightScroll(){}
    virtual void leftScroll(){}

    Selectable* getNext();
    Selectable* getPrev();
    String getText();
    void setText(String text);
    void setNext(Selectable *next);
    void setPrev(Selectable *prev);

protected:

    String text;
    Selectable* next;
    Selectable* prev;
};

#endif //SELECTABLEINTERFACE_H
