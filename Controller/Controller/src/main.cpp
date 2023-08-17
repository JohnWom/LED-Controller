#include <Arduino.h>
#include "setup.h"

// Cursor Symbol for LCD
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

ScreenManager *SM;

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);

    Serial.println("Turning on Pins...");
    pinMode(VRx, INPUT);
    pinMode(VRy, INPUT);
    pinMode(SW, INPUT_PULLUP);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    Serial.println("Building Screens...");
    SM = setupScreens::main();
    Serial.println("Screens Built");

    Serial.println("Starting LCD...");
    DFRobot_RGBLCD1602* display = SM->getDisplay();
    display->init();
    display->setBacklight(true);
    display->display();
    display->customSymbol(0, cursor_symbol);
    display->print("Welcome to LED");


    Serial.println("Starting first Screen...");
    SM->draw();
    SM->draw_cursor();
    Serial.println("Finished Boot Up");
}

void loop() {
    SM->joystickRead();
}