#include "ScreenSelectable.h"


ScreenSelectable::ScreenSelectable(char* t) {
  text = t;
}

Screen* ScreenSelectable::nextScreen() {
  return screen;
}

void ScreenSelectable::setScreen(Screen *s) {
  screen = s;
}