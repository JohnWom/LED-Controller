#ifndef FUNCSELECTABLE
#define FUNCSELECTABLE

#include "Selectables.h"


class FuncSelectable:Selectable 
{
  public:
    FuncSelectable(char, Selectable*, Selectable*, funcptr);

    void exec();
    
  private:
    funcptr FPn;
};

#endif