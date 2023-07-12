//
// Created by johnw on 7/8/2023.
//

#include "Operator.h"

Operator::Operator(Communicator* c, Adafruit_NeoPixel* l, int nleds) {
    communicator = c;
    leds = l;
    num_leds = nleds;

    // default setting is SolidColor and Off
    r = 20; g = 0; b = 0;
    pattern = new SolidColor(leds, num_leds, r, g, b);

}

Operator::~Operator() {
    delete pattern;
    delete communicator;
}

void Operator::main() {
    Command_t command = communicator->getCommand();

    switch (command.type) {
        case Command::COLOR:
            r = command.r;
            g = command.g;
            b = command.b;
            pattern->setColors(r, g, b);
            Serial.println("Color Changed");
            break;
        case Command::STATIC_P: {   // curly braces here keep new_p in case's scope
            Pattern *new_p = processStatic(command.value);
            startPattern(new_p);
            break;
        }
        case Command::MUSIC_P: {
            Pattern *new_p = processMusic(command.value);
            startPattern(new_p);
            Serial.println("Music Pattern Selected");
            break;
        }
        case Command::NONE:
            pattern->nextStep();
            break;
    }

}

void Operator::startPattern(Pattern* new_pattern) {
    delete pattern;
    pattern = new_pattern;
    pattern->firstStep();

}

Pattern* Operator::processStatic(int code) {
    switch (code) {
        case 0:
            Serial.println("Solid Color Selected");
            return new SolidColor(leds, num_leds, r, g, b);
        case 1:
            Serial.println("Party 1 Selected");
            return new CenterPulseWhole(leds, num_leds, r, g, b);
        case 2:
            Serial.println("Party 2 Selected");
            return new CenterPulseSplit(leds, num_leds, r, g, b, 1);
        default:
            Serial.println("Default Selected");
            return new SolidColor(leds, num_leds, r, g, b);
    }
}

Pattern* Operator::processMusic(int code) {
    switch (code) {
        default:
            return new SolidColor(leds, num_leds, r, g, b);
    }
}