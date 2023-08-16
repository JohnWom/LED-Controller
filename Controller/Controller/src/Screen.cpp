//
// Created by johnw on 7/12/2023.
//

#include "Screen.h"

Screen::Screen():
    topItem(),
    bottomItem()
    {}

Screen::Screen(Selectable *t, Selectable *b):
    topItem(t),
    bottomItem(b)
    {}

void Screen::scrollUp() {
    if (topItem->getPrev() != nullptr){
        bottomItem = topItem;
        topItem = topItem->getPrev();
    }
}

void Screen::scrollDown() {
    if (bottomItem->getNext() != nullptr){
        topItem = bottomItem;
        bottomItem = bottomItem->getNext();
    }
}

Selectable *Screen::getTopItem() const {
    return topItem;
}

void Screen::setTopItem(Selectable *topItem) {
    Screen::topItem = topItem;
}

Selectable *Screen::getBottomItem() const {
    return bottomItem;
}

void Screen::setBottomItem(Selectable *bottomItem) {
    Screen::bottomItem = bottomItem;
}
