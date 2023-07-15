//
// Created by johnw on 7/12/2023.
//

#include "Operator.h"

Operator::Operator(Screen *s) {
    current_screen = s;
    display = new DFRobot_RGBLCD1602(16, 2);
    cursor_position = 0;
}

void Operator::draw() {
    Serial.println("Drawing...");

    display->setCursor(1, 0);
    display->print(current_screen->getTopItem()->getText());

    display->setCursor(1, 1);
    display->print(current_screen->getBottomItem()->getText());
    Serial.println("Drawing Done");
}

void Operator::draw_cursor() {
    display->setCursor(0, cursor_position);
    display->write((unsigned char)0);
    // Clear other cursor
    if (cursor_position) {
        display->setCursor(0, 0);
        display->print(" ");
    }
    else {
        display->setCursor(0, 1);
        display->print(" ");
    }
}

void Operator::callback(Screen *s) {
    current_screen = s;
}

void Operator::upScroll() {
    if (cursor_position == 0) {
        // Roll Options
        current_screen->scrollUp();
        draw();
    }
    else {
        cursor_position = 0;
        draw_cursor();
        Serial.println("Cursor Drawn");
    }
}

void Operator::downScroll() {
    if (cursor_position == 1) {
        current_screen->scrollDown();
        draw();
    }
    else {
        cursor_position = 1;
        draw_cursor();
        Serial.println("Cursor Drawn");
    }
}

void Operator::rightScroll() {
    Selectable* current = getCurrent();
    current->rightScroll();
    draw();
}

void Operator::leftScroll() {
    Selectable* current = getCurrent();
    current->leftScroll();
    draw();
}

void Operator::click() {
    Selectable* current = getCurrent();
    current->execute();
}

void Operator::joystickRead() {
    int yPosition = analogRead(VRy);
    int xPosition = analogRead(VRx);
    int SW_state = digitalRead(SW);

    if (SW_state == 0) {
        Serial.println("Button Clicked!");
        click();
        draw();
    }
    //Define mapY
    if (yPosition > 910) {
        upScroll();
        Serial.println("Scrolled Up");
        delay(200);
    } else if (yPosition < 150) {
        downScroll();
        Serial.println("Scrolled Down");
        delay(200);
    }

    // Define mapX
    if (xPosition > 910) {
        leftScroll();
//        delay(10);
    } else if (xPosition < 150) {
        rightScroll();
//        delay(10);
    }
}

Selectable* Operator::getCurrent() {
    Selectable* current;
    // Set current to item cursor is on
    if (cursor_position == 0) {
        current = current_screen->getTopItem();
    } else {
        current = current_screen->getBottomItem();
    }

    return current;
}

DFRobot_RGBLCD1602 *Operator::getDisplay() const {
    return display;
}
