


class Selectable {
  public:
    //goes to next
    Selectable* next() {
      return next;
    }

    //goes to prev
    Selectable* prev() {
      return prev;
    }

  private:
    char text[15];
    Selectable* next;
    Selectable* prev;
};

//selectable for functions
class FuncSelectable:Selectable 
{
  public:

    Selectable(char text[15] = "               ", Selectable* next = NULL, Selectable* prev = NULL, funcptr FPn) {
      text = text;
      next = next;
      prev = prev;
      F = FPn;
    }

    void exec() {
      (*funcptr)();
    }

  private:
   funcptr F;
   Selectable* next;
   Selectable* prev;
   char text[15];
};

//selectable for screens
class ScreenSelectable:Selectable 
{
  public:
    Selectable(char text[15] = "               ", Selectable* next = NULL, Selectable* prev = NULL, Screen* sc = NULL) {
      text = text;
      next = next;
      prev = prev;
      screen = sc;
    }
    
    Screen* nextScreen() {
      return Screen;
    }

  private:
    Screen* Screen;
};

