#ifndef SELECCTABLES.H
#define SELECTABLES .H

class Selectable {
  public:
  // Parameterized Constructor with default blank screen and null pointers
  Selectable(char text[15], Selectable* next, Selectable* prev, Screen* scr, void *funcpoint());

  //goes to next
  typedef Selectable*(Selectable::*next)(void);

  //goes to prev

  typedef Selectable*(Selectable::*prev)(void);

  //executes function
  typedef void(Selectable::*exec)(void);

  private:
    char text[15];
    void *funcpoint();
    Selectable* next;
    Selectable* prev;
    Screen* screen;
};


#endif