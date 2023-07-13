//
// Created by johnw on 7/12/2023.
//
#include "SelectableInterface.h"

Selectable::Selectable(char* t, Selectable* n, Selectable* p) {
    text = t;
    next = n;
    prev = p;
}



char* Selectable::getText() {
    return text;
}

Selectable* Selectable::getNext() {
    return next;
}

Selectable* Selectable::getPrev() {
    return prev;
}

void Selectable::setText(char *text) {
    Selectable::text = text;
}

void Selectable::setNext(Selectable *next) {
    Selectable::next = next;
}

void Selectable::setPrev(Selectable *prev) {
    Selectable::prev = prev;
}
