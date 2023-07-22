#include <Arduino.h>
#include "setup.h"

byte cursor_symbol[8] {
        0b00000,
        0b01000,
        0b00100,
        0b00010,
        0b00001,
        0b00010,
        0b00100,
        0b01000
};

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);

    Serial.println("Turning on Pins...");
    pinMode(VRx, INPUT);
    pinMode(VRy, INPUT);
    pinMode(SW, INPUT_PULLUP);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    Serial.println("Starting LCD...");
    DFRobot_RGBLCD1602* display = Op->getDisplay();
    display->init();
    display->setBacklight(true);
    display->display();
    display->customSymbol(0, cursor_symbol);
    display->print("Welcome to LED");
    delay(2000);

    Serial.println("Linking Selectables...");
    connect_selectables();

    Serial.println("Starting first Screen...");
    Op->draw();
    Op->draw_cursor();
    Serial.println("Finished Boot Up");
}

void loop() {
    Op->joystickRead();
}