#ifndef OPERATOR
#define OPERATOR

#include <string.h>
#include <mbed.h>
#include <rtos.h>
#include <platform/Callback.h>
#include "patterns.h"

using namespace rtos;

// Operator Class
// Class handles control logic for slave chip system
// Main responsibilites are reading the serial port for incoming commands
// and executing those commands, process functions aid in command handling

class Operator
{
  public:

    Operator();
    
    void readSerial(void);

    static void runPattern();

  private:
    Thread* t;

    static void (*pattern)(void);

    void processColor(String);

    void processStaticPattern(String);

    void processMusicPattern(String);

  friend class Patterns;
};

#endif