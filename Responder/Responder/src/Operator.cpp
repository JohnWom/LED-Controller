//
// Created by johnw on 7/8/2023.
//

#include "Operator.h"

Operator::Operator(Communicator* c, CRGB* l, int nleds):
        communicator(c),
        colors(new vector<CRGB>()),
        pattern(new SolidColor(leds, numLeds, colors)),
        leds(l),
        numLeds(nleds)

{
    // default pattern is Solid Color

    colors->push(CRGB(100, 0, 0));   // Default Primary Color is Red
    colors->push(CRGB(0, 100, 0));   // Default Secondary Color is Green
    colors->push(CRGB(0, 0, 100));   // Default Tertiary Color is Blue
}

Operator::~Operator() {
    delete pattern;
    delete communicator;
}

void Operator::main() {
    Command_t command = communicator->getCommand();

    switch (command.type) {
        case Command::COLOR:
            // Change Color in Operator
            colors->push(CRGB(command.r, command.g, command.b), command.value);
            Serial.println("Color Changed");
            break;

        case Command::STATIC_P: {   // curly braces here keep newP in case's scope
            Pattern *newP = processStatic(command.value);
            startPattern(newP);
            break;
        }
        case Command::MUSIC_P: {
            Pattern *newP = processMusic(command.value);
            startPattern(newP);
            break;
        }
        case Command::NONE:
            pattern->nextStep();
            break;
    }

}

void Operator::startPattern(Pattern* newPattern) {
    delete pattern;       // Reset the Pattern
    pattern = newPattern;
    pattern->firstStep();

}

Pattern* Operator::processStatic(int code) {
    switch (code) {
        case 0:
            Serial.println("Solid Color Selected");
            return new SolidColor(leds, numLeds, colors);
        case 1:
            Serial.println("Party 1 Selected");
            return new Party1(leds, numLeds, colors);
        case 2:
            Serial.println("Party 2 Selected");
            return new Party2(leds, numLeds, colors);
        case 3:
            Serial.println("Party 3 Selected");
            return new CenterPulseSplit(leds, numLeds, colors);
        case 4:
            Serial.println("Rainbow Selected");
            return new Rainbow(leds, numLeds);
        case 5:
            Serial.println("Three Color Selected");
            return new ThreeColor(leds, numLeds, colors);
        case 6:
            Serial.println("Ocean Selected");
            return new Ocean(leds, numLeds);
        case 7:
            Serial.println("Insanity Selected");
            return new Insanity(leds, numLeds);
        default:
            Serial.println("Default Selected");
            return new SolidColor(leds, numLeds, colors);
    }
}

Pattern* Operator::processMusic(int code) {
    switch (code) {
        default:
            return new SolidColor(leds, numLeds, colors);
    }
}