#ifndef OPERATOR
#define OPERATOR

#include <string.h>
#include <mbed.h>
#include <rtos.h>
#include <platform/Callback.h>
#include "patterns.h"

using namespace rtos;


class Operator
{
  public:

    Operator(Thread*);
    
    void readSerial(void);

  private:

    static void (*pattern)(void);
    Thread* thread;

    static void runPattern();

    void processColor(String);

    void processStaticPattern(String);

    void processMusicPattern(String);

  friend class Patterns;
};

#endif