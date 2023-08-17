//
// Created by johnw on 7/12/2023.
//

#include "ScreenManager.h"

ScreenManager::ScreenManager():
        currentScreen(),
        display(new DFRobot_RGBLCD1602(16,2)),
        cursorPosition(0)
    {}

ScreenManager::ScreenManager(Screen *s):
        currentScreen(s),
        display(new DFRobot_RGBLCD1602(16,2)),
        cursorPosition(0)
        {}

void ScreenManager::draw() {
    // Prints Selectables onto LCD
    Serial.println("Drawing...");

    display->setCursor(1, 0);
    display->print(currentScreen->getTopItem()->getText());

    display->setCursor(1, 1);
    display->print(currentScreen->getBottomItem()->getText());
    Serial.println("Drawing Done");
}

void ScreenManager::draw_cursor() {
    // Draws the Cursor
    display->setCursor(0, cursorPosition);
    display->write((unsigned char)0);

    // Clear other cursor
    if (cursorPosition) {
        display->setCursor(0, 0);
        display->print(" ");
    }
    else {
        display->setCursor(0, 1);
        display->print(" ");
    }
}

void ScreenManager::callback(Screen *s) {
    // Callback for screen pointers
    currentScreen = s;
}

void ScreenManager::upScroll() {
    if (cursorPosition == 0) {
        // Roll Options
        currentScreen->scrollUp();
        draw();
    }
    else {
        cursorPosition = 0;
        draw_cursor();
        Serial.println("Cursor Drawn");
    }
}

void ScreenManager::downScroll() {
    if (cursorPosition == 1) {
        currentScreen->scrollDown();
        draw();
    }
    else {
        cursorPosition = 1;
        draw_cursor();
        Serial.println("Cursor Drawn");
    }
}

void ScreenManager::rightScroll() {
    Selectable* current = getCurrent();
    current->rightScroll();
    draw();
}

void ScreenManager::leftScroll() {
    Selectable* current = getCurrent();
    current->leftScroll();
    draw();
}

void ScreenManager::click() {
    Selectable* current = getCurrent();
    current->execute();
}

void ScreenManager::joystickRead() {
    int yPosition = analogRead(VRy);
    int xPosition = analogRead(VRx);
    int SW_state = digitalRead(SW);

    if (SW_state == 0) {
        Serial.println("Button Clicked!");
        click();
        draw();
    }
    //Define mapY
    if (yPosition > 930) {
        upScroll();
        Serial.println("Scrolled Up");
        delay(200);
    } else if (yPosition < 150) {
        downScroll();
        Serial.println("Scrolled Down");
        delay(200);
    }

    // Define mapX
    // Defined as else if so that only one direction is scrollable at a time
    else if (xPosition > 910) {
        leftScroll();
    // delay(10);
    } else if (xPosition < 150) {
        rightScroll();
    // delay(10);
    }
}

Selectable* ScreenManager::getCurrent() {
    // Helper Method for locating current Selectable
    Selectable* current;
    // Set current to item cursor is on
    if (cursorPosition == 0) {
        current = currentScreen->getTopItem();
    } else {
        current = currentScreen->getBottomItem();
    }

    return current;
}

DFRobot_RGBLCD1602 *ScreenManager::getDisplay() const {
    return display;
}

void ScreenManager::setScreen(Screen *s) {
    currentScreen = s;
}