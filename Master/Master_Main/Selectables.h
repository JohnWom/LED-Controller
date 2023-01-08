#ifndef SELECCTABLES.H
#define SELECTABLES .H

#include "types.h"

class Selectable {
  public:
  //goes to next
  Selectable* next();

  //goes to prev

  Selectable* prev();

  //set next
  Selectable* setNext(Selectable*);

  //set prev
  Selectable* setPrev(Selectable*);

  private:
    char text[15];
    void *funcpoint();
    Selectable* next;
    Selectable* prev;

};

//selectable for functions
class FuncSelectable:Selectable 
{
  public:
    Selectable(char, Selectable*, Selectable*, funcptr);

    void exec();
    
  private:
    funcptr FPn;
};

//selectable for screens
class ScreenSelectable:Selectable 
{
  public:
    Selectable(char, Selectable*, Selectable*, Screen*);

    Screen* nextScreen();

    Screen* setScreen(Screen* s);

  private:
    Screen* Screen;
};

#endif