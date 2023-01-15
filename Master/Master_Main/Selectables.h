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
  void setNext(Selectable*);

  //set prev
  void setPrev(Selectable*);

  private:
    char text[15];
    void *funcpoint();
    Selectable* next;
    Selectable* prev;

};

#endif