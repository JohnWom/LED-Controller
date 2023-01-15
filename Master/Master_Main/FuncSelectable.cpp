#include "FuncSelectable.h"

FuncSelectable::FuncSelectable(char text[15] = "               ", Selectable* next = NULL, Selectable* prev = NULL, funcptr FPn) {
  text = text;
  next = next;
  prev = prev;
  F = FPn;
}

void FuncSelectable::exec() {
  (*funcptr)();
}
