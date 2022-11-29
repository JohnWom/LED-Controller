


class Selectable {
  public:
    // Parameterized Constructor with default blank screen and null pointers
    Selectable(char text[15] = "               ", Selectable* next = NULL, Selectable* prev = NULL, Screen* sc = NULL, void *funcpoint()) {
      text = text;
      next = next;
      prev = prev;
      screen = sc;

      void *functpoint() = *functpoint();
    }

    //goes to next
    Selectable* next() {
      return next;
    }

    //goes to prev

    Selectable* prev() {
      return prev;
    }

    //executes function
    void exec() {
      (*functpoint)();
    }

  private:
    char text[15];
    void *funcpoint();
    Selectable* next;
    Selectable* prev;
    Screen* screen;
};