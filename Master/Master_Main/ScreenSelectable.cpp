#include "ScreenSelectable.h"

ScreenSelectable::ScreenSelectable(char text[15] = "               ", Selectable* next = NULL, Selectable* prev = NULL, Screen* sc = NULL) {
  text = text;
  next = next;
  prev = prev;
  screen = sc;
}

Screen* ScreenSelectable::nextScreen() {
  return screen;
}

void ScreenSelectable::setScreen(Screen *s) {
  screen = s;
}