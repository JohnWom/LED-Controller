#ifndef SELECCTABLES.H
#define SELECTABLES .H

// define function pointer type
typedef void (*funcptr)();

class Selectable {
  public:
  //goes to next
  Selectable* next();

  //goes to prev

  Selectable* prev();

  private:
    char text[15];
    void *funcpoint();
    Selectable* next;
};

//selectable for functions
class FuncSelectable:Selectable 
{
  public:
    Selectable(char, Selectable*, Selectable*, funcptr);

    void exec();

  private:
    funcptr;
};

//selectable for screens
class ScreenSelectable:Selectable 
{
  public:
    Selectable(char, Selectable*, Selectable*, Screen*);

    Screen* nextScreen();

  private:
    Screen* Screen;
};

#endif