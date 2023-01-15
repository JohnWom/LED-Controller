#ifndef FUNCSELECTABLE
#define FUNCSELECTABLE

#include "Selectables.h"
#include <Arduino.h>    

class FuncSelectable : public Selectable 
{
  public:
    FuncSelectable(char* = "               ", funcptr = NULL);

    void exec();
    
  private:
    funcptr FPn;
};

#endif