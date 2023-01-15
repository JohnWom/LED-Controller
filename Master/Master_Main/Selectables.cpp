#include "Selectables.h"


Selectable* Selectable::next() {
  return nextItem;
}

Selectable* Selectable::prev() {
  return prevItem;
}

void Selectable::setNext(Selectable* n){
  nextItem = n;
}

void Selectable::setPrev(Selectable* p) {
  prevItem = p;
}