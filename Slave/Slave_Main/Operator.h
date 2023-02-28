#ifndef OPERATOR
#define OPERATOR

#include "types.h"
#include <string.h>
#include <mbed.h>
#include <rtos.h>
#include <platform/Callback.h>
#include "patterns.h"

using namespace rtos;


class Operator
{
  public:

    Operator(Thread*, Patterns*);
    
    void readSerial(void);

    void runPattern(void);

  private:

    funcptr pattern;
    Patterns* P;
    Thread* thread;

    void runPattern();

    void processColor(String);

    void processStaticPattern(String);

    void processMusicPattern(String);

  friend class Patterns;
};

#endif