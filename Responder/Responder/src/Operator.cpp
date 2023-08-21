//
// Created by johnw on 7/8/2023.
//

#include "Operator.h"

Operator::Operator(Communicator* c, CRGB* l, int nleds):
        communicator(c),
        pattern(new SolidColor(leds, numLeds, 0, 0, 0)),
        leds(l),
        numLeds(nleds),
        colors()
{
    // default setting is SolidColor and Off
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
            if (command.r <= 255)
                colors[command.value][RED] = command.r;
            if (command.g <= 255)
                colors[command.value][GREEN] = command.g;
            if (command.b <= 255)
                colors[command.value][BLUE] = command.b;

            // Change Color in the Pattern
            pattern->setColors(r, g, b);
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
    delete pattern;
    pattern = newPattern;
    pattern->firstStep();

}

Pattern* Operator::processStatic(int code) {
    switch (code) {
        case 0:
            Serial.println("Solid Color Selected");
            return new SolidColor(leds, numLeds, r, g, b);
        case 1:
            Serial.println("Party 1 Selected");
            return new Party1(leds, numLeds, r, g, b);
        case 2:
            Serial.println("Party 2 Selected");
            return new Party2(leds, numLeds, r, g, b);
        case 3:
            Serial.println("Party 3 Selected");
            return new CenterPulseSplit(leds, numLeds, r, g, b, 1);
        case 4:
            Serial.println("Rainbow Selected");
            return new Rainbow(leds, numLeds);
        case 5:
            Serial.println("Three Color Selected");
            return new ThreeColor(leds, numLeds, r, g, b);
        case 6:
            Serial.println("Ocean Selected");
            return new Ocean(leds, numLeds);
        case 7:
            Serial.println("Insanity Selected");
            return new Insanity(leds, numLeds);
        default:
            Serial.println("Default Selected");
            return new SolidColor(leds, numLeds, r, g, b);
    }
}

Pattern* Operator::processMusic(int code) {
    switch (code) {
        default:
            return new SolidColor(leds, numLeds, r, g, b);
    }
}