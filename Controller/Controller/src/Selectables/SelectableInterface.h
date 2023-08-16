//
// Created by johnw on 7/12/2023.
//

#ifndef SELECTABLEINTERFACE_H
#define SELECTABLEINTERFACE_H

#include <Arduino.h>

/*
 * This is the base class for Selectable elements
 * These elements from the lines of the GUI, and
 * are joined in an acyclic doubly linked list
*/

class Selectable
{
public:
    explicit Selectable(char*);
    Selectable(char*, Selectable*, Selectable*);

    virtual void execute()=0;

    // Special Commands for in-selectable controls
    // Enables joystick input to control a Selectable
    // does nothing by default, but can be implemented by choice
    virtual void rightScroll(){}
    virtual void leftScroll(){}

protected:
    String text;
    Selectable* next;
    Selectable* prev;

public:
    // Getters & Setters
    Selectable* getNext();
    void setNext(Selectable *next);

    Selectable* getPrev();
    void setPrev(Selectable *prev);

    String getText();
    void setText(char* text);
};

#endif //SELECTABLEINTERFACE_H
