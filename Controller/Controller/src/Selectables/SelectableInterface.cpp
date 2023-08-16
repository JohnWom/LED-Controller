//
// Created by johnw on 7/12/2023.
//
#include "SelectableInterface.h"

Selectable::Selectable(char *t):
    text(t),
    next(),
    prev()
{}

Selectable::Selectable(char* t, Selectable*p, Selectable*n):
    text(t),
    next(n),
    prev(p)
    {}



String Selectable::getText() {
    return text;
}

Selectable* Selectable::getNext() {
    return next;
}

Selectable* Selectable::getPrev() {
    return prev;
}

void Selectable::setText(char* t) {
    Selectable::text = t;
}

void Selectable::setNext(Selectable *n) {
    Selectable::next = n;
}

void Selectable::setPrev(Selectable *p) {
    Selectable::prev = p;
}
