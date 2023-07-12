#include "SelectableFactory.h"

SelectableFactory::SelectableFactory() {

}

SelectableFactory::make_first(char * text, funcptr func, Screen* screen) {
  Selectable s;
  s.text = text;
  s.functpoint = func;
  s.next_screen = screen;
  return s;
}

SelectableFactory::add_selectable(Selectable* head, char* text, funcptr func, Screen* screen) {
  Selectable s;
  s.text = text;
  s.functpoint = func;
  s.next_screen = screen;
  
}