//
// Created by johnw on 7/8/2023.
//

#ifndef OPERATOR_H
#define OPERATOR_H

#include "patterns.h"
#include "Communication/Command.h"
#include "Communication/SerialReader.h"

class Operator
{
public:
    Operator(Communicator*, Adafruit_NeoPixel*, int);

    void main();

    ~Operator();
private:

    void startPattern(Pattern*);  // Swap pattern pointer, freeing old pattern, and start new pattern


    Pattern* processStatic(int);   // Factory Function for Static Patterns
    Pattern* processMusic(int);    // Factor Function for Music Patterns

    Communicator* communicator;
    Pattern* pattern;
    Adafruit_NeoPixel* leds;
    int num_leds;

    unsigned short r;  // allows color to persist through patterns
    unsigned short g;
    unsigned short b;
};


#endif //OPERATOR_H
