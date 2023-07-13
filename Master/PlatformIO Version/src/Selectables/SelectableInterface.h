//
// Created by johnw on 7/12/2023.
//

#ifndef SELECTABLEINTERFACE_H
#define SELECTABLEINTERFACE_H

class Selectable
{
public:
    Selectable(char*, Selectable*, Selectable*);
    virtual void execute()=0;

    // Special Commands for in-selectable controls
    // Enables joystick input -> Selectable
    virtual void rightScroll(){}
    virtual void leftScroll(){}

    Selectable* getNext();
    Selectable* getPrev();
    char* getText();
    void setText(char *text);
    void setNext(Selectable *next);
    void setPrev(Selectable *prev);

protected:

    char* text;
    Selectable* next;
    Selectable* prev;
};

#endif //SELECTABLEINTERFACE_H
