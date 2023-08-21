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
    enum rgb {RED, GREEN, BLUE};
public:
    Operator(Communicator*, CRGB*, int);

    void main();

    ~Operator();
private:

    void startPattern(Pattern*);  // Swap pattern pointer, freeing old pattern, and start new pattern


    Pattern* processStatic(int);   // Factory Function for Static Patterns
    Pattern* processMusic(int);    // Factor Function for Music Patterns

    Communicator* communicator;
    Pattern* pattern;
    CRGB* leds;
    int numLeds   ;

    unsigned short colors[3][3];    // Array of Primary, Secondary, and Tertiary Colors
};


#endif //OPERATOR_H
