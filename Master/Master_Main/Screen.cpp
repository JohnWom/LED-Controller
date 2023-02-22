#include "Screen.h"
#include <Arduino.h>

    // Default Parameterized Constructor
Screen::Screen(Selectable* top, Selectable* bottom) {
    top_item = top;
    bottom_item = bottom;
}

    // Scroll Up
void Screen::scrollUp() { 
    if (top_item->prev != NULL){
      bottom_item = top_item;
      top_item = top_item->prev; 
    }
}

void Screen::scrollDown() {
    if (bottom_item->next != NULL){
      top_item = bottom_item;
      bottom_item = bottom_item->next;
    }       
}


