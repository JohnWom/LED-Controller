//
// Created by johnw on 7/12/2023.
//
#include "SelectableInterface.h"

Selectable::Selectable(String t, Selectable*p, Selectable*n) {
    text = t;
    next = n;
    prev = p;
}



String Selectable::getText() {
    return text;
}

Selectable* Selectable::getNext() {
    return next;
}

Selectable* Selectable::getPrev() {
    return prev;
}

void Selectable::setText(String text) {
    Selectable::text = text;
}

void Selectable::setNext(Selectable *next) {
    Selectable::next = next;
}

void Selectable::setPrev(Selectable *prev) {
    Selectable::prev = prev;
}
