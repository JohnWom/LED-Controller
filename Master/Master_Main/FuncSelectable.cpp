#include "FuncSelectable.h"

FuncSelectable::FuncSelectable(char* t, funcptr F) {
  text = t;
  FPn = F;
}

void FuncSelectable::exec() {
  (*FPn)();
}
