//
// Created by johnw on 7/13/2023.
//

#include "SelectableFactory.h"

SelectableFactory::SelectableFactory() {
    num_music = 0;
    num_static = 0;
}

void SelectableFactory::addSelectable(Selectable *head, Selectable *s) {
    if (head->getNext() == nullptr) {
        head->setNext(s);
        s->setPrev(head);
    }
    else {
        Selectable* n = head->getNext();
        head->setNext(s);
        n->setPrev(s);
        s->setPrev(head);
        s->setNext(n);
    }

}


Selectable* SelectableFactory::make_selectable(String text, int type) {
    text = fillText(text);
    char txt[15];
    text.toCharArray(txt, 15);
    if (type == COLOR) {
        return new FunctionSelectable(txt, nullptr);
    }
    else if (type == STATIC) {
        String msg = "SP";
         msg += String(num_static++);

        return new FunctionSelectable(txt, nullptr);
    }
    else if (type == MUSIC) {
        return new FunctionSelectable(txt, nullptr);
    }
    else if (type == NUM) {
        return new NumberSelectable(txt, 0, 0, 0);
    }
    else if (type == SCREEN) {
        return new ScreenSelectable(txt, nullptr, nullptr);
    }
}


String SelectableFactory::fillText(String text) {
    unsigned int len = text.length();
    for (int i=0; i<(15-len); i++)
        text += " ";

    return text;
}