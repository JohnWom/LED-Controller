#include "Operator.h"


Operator::Operator(Thread* t)
{

  pattern = &Patterns::Solid_Color;

  thread = t;
}

void Operator::readSerial() 
{
  String code;

  if (Serial1.available()) {
    code = Serial1.readString();
    code.trim();

    thread->terminate();

    if (code.charAt(0) == 'C')
      processColor(code);
    else if (code.charAt(0) == 'M')
      processMusicPattern(code);
    else if (code.charAt(0) == 'S')
      processStaticPattern(code);

    thread->start(mbed::callback(runPattern));
  }
}

void Operator::runPattern(void){
  (*pattern)();
}

void Operator::processColor(String code)
{
  String red = code.substring(1,3);

  String green = code.substring(4,6);

  String blue = code.substring(7,9);

  Patterns::r = red.toInt();
  Patterns::g = green.toInt();
  Patterns::b = blue.toInt();
}

void Operator::processStaticPattern(String code)
{
  int pattern_num = code.substring(1,9).toInt();

  switch (pattern_num)
  {
    case 0:
      pattern = &Patterns::Solid_Color;
      break;
    case 1:
      pattern = &Patterns::Color_Cycle;
      break;
    case 2:
      pattern = &Patterns::Rainbow;
      break;
  }
}

void Operator::processMusicPattern(String code)
{
  int pattern_num = code.substring(1,9).toInt();

  switch (pattern_num)
  {
    case 0:
      pattern = &Patterns::Simple_Music;
      break;
  }
}