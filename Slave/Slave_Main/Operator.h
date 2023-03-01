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

    Operator();
    
    void readSerial(void);

    static void runPattern();

  private:

    static void (*pattern)(void);

    void processColor(String);

    void processStaticPattern(String);

    void processMusicPattern(String);

  friend class Patterns;
};

#endif