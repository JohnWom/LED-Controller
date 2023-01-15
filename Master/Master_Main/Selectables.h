#ifndef SELECTABLES.H
#define SELECTABLES.H

#include "types.h"

class Screen;

class Selectable {
  public:
  //goes to next
  Selectable* next();

  //goes to prev

  Selectable* prev();

  //set next
  void setNext(Selectable*);

  //set prev
  void setPrev(Selectable*);

  //exec for function derrived class
  virtual void exec(){}

  virtual Screen* nextScreen(){}

  private:
    char* text;
    void *funcpoint();
    Selectable* nextItem;
    Selectable* prevItem;

  friend class Screen;
  friend class Operator;
  friend class FuncSelectable;
  friend class ScreenSelectable;

};

#endif