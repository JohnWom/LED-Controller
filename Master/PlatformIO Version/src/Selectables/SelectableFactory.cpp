//
// Created by johnw on 7/12/2023.
//

#include "SelectableFactory.h"

SelectableFactory::SelectableFactory() {
    num_music = 0;
    num_static = 0;
}


void SelectableFactory::addSelectable(Selectable* newSelectable, Selectable* head) {
    // Adds selectable to linked list
    if (head->getNext() == nullptr) {
        head->setNext(newSelectable);
        newSelectable->setPrev(head);
    }
    else {
        Selectable* next = head->getNext();
        head->setNext(newSelectable);
        newSelectable->setPrev(newSelectable);
        newSelectable->setNext(next);
        next->setPrev(newSelectable);
    }
}


String SelectableFactory::createCommand(int type, int h, int s, int v) {
    String message;
    if (type == Command::COLOR) {
        message = "C";
        message += String(h);
        message += String(s);
        message += String(v);
    }
    else if (type == Command::STATIC_P) {
        message = "SP";
        String num = String(num_static);

        // Add in 0's
        unsigned int len = num.length();
        for (int i=0; i<(8-len); i++)
            message += "0";

        message += num;
        num_static++;

    }
    else if (type == Command::MUSIC_P) {
        message = "MP";
        String num = String(num_music);

        // Add in 0's
        unsigned int len = num.length();
        for (int i=0; i<(8-len); i++)
            message += "0";

        message += num;
        num_music++;
    }

    char msg[10];
    message.toCharArray(msg, 10);
    return msg;
}

String SelectableFactory::fillText(char* msg) {
    String text = String(msg);
    int len = text.length();
    for (int i=0; i<(15-len); i++)
        text += " ";

    return text;
}