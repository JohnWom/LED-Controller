//
// Created by johnw on 7/8/2023.
//

#include "Operator.h"

Operator::Operator(Communicator* c, Adafruit_NeoPixel* l, int nleds) {
    communicator = c;
    leds = l;
    num_leds = nleds;

    // default setting is SolidColor and Off
    r = 0; g = 0; b = 200;
    pattern = new SolidColor(leds, num_leds, r, g, b);
    pattern->firstStep();

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
//            pattern->setColors(r, g, b);
            break;
        case Command::STATIC_P: {   // curly braces here keep new_p in case's scope
//            Pattern *new_p = processStatic(command.value);
//            startPattern(new_p);
            break;
        }
        case Command::MUSIC_P: {
//            Pattern *new_p = processMusic(command.value);
//            startPattern(new_p);
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
            return new SolidColor(leds, num_leds, r, g, b);
        default:
            return new SolidColor(leds, num_leds, r, g, b);
    }
}

Pattern* Operator::processMusic(int code) {
    switch (code) {
        default:
            return new SolidColor(leds, num_leds, r, g, b);
    }
}