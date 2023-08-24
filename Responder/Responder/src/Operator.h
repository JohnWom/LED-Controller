//
// Created by johnw on 7/8/2023.
//

#ifndef OPERATOR_H
#define OPERATOR_H

#include "patterns.h"
#include "Communication/Command.h"
#include "Communication/SerialReader.h"
#include "Tools/vector.h"
#include "Tools/SharedPointer.h"


class Operator
{
    enum rgb {RED, GREEN, BLUE};
public:
    Operator(Communicator*, CRGB*, int);

    void main();

    ~Operator();
private:

    void startPattern(Pattern*);  // Swap pattern pointer, freeing old pattern, and start new pattern

    void processColor(Command_t &); // Processes Setting a Color
    Pattern* processStatic(int);    // Factory Function for Static Patterns
    Pattern* processMusic(int);     // Factor Function for Music Patterns

    Communicator* communicator;
    SharedPointer<vector<CRGB>> colors;    // Vector of color arrays
    Pattern* pattern;
    CRGB* leds;
    int numLeds;


};


#endif //OPERATOR_H
