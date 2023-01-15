


Selectable* Selectable::next() {
  return next;
}

Selectable* Selectable::prev() {
  return prev;
}

void Selectable::setNext(Selectable* n){
  next = n;
}

void Selectable::setPrev(Selectable* p) {
  prev = p;
}
