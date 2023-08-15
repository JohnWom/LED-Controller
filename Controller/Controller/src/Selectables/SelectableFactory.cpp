//
// Created by johnw on 7/13/2023.
//

#include "SelectableFactory.h"

void SelectableFactory::buildScreen(Screen *screen, Selectable *selectables, int n_selectables) {
    for (int i=n_selectables-2; i>=0; i--) {
        addSelectable(selectables[n_selectables-1], selectables[i]);
    }
    screen->setTopItem(&selectables[0]);
    screen->setBottomItem(&selectables[1]);
}

Selectable* SelectableFactory::colorFunction(String text, int type, const int color[3]) {
    // Build Code
    String code = "C";
    code += String(type);
    for (int i=0; i<3; i++)
        code += String(color[i]);

    text = fillText(text);  // Make sure text is 15 points
    return new FunctionSelectable(text, code);
}

void SelectableFactory::addSelectable(Selectable &head, Selectable &s) {
    if (head.getNext() == nullptr) {
        head.setNext(&s);
        s.setPrev(&head);
    }
    else {
        Selectable* n = head.getNext();
        head.setNext(&s);
        n->setPrev(&s);
        s.setPrev(&head);
        s.setNext(n);
    }
}

String SelectableFactory::fillText(String text) {
    unsigned int len = text.length();
    for (int i=0; i<(15-len); i++)
        text += " ";

    return text;
}