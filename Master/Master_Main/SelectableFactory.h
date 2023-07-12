#ifndef SELECTABLE_FACTORY_H
#define SELECTABLE_FACTORY_H

#include Screen.h
class SelectableFactory 
{
public:
  SelectableFactory();

  Selectable make_first(char*, funcptr=NULL, Screen*=NULL);

  void add_selectable(Selectable* , char*, funcptr, Screen* NULL);

private:

}


#endif