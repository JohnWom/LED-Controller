#include "Operator.h"


Operator::Operator()
{
  pattern = &Patterns::Solid_Color;
}

void Operator::readSerial() 
{
  String code;

  if (Serial1.available()) {
    code = Serial1.readString();
    code.trim();

    Serial.println(code);
    

    if (code.charAt(0) == 'C')
      processColor(code);
    else if (code.charAt(0) == 'M')
      processMusicPattern(code);
    else if (code.charAt(0) == 'S')
      processStaticPattern(code);
  }
}

void Operator::runPattern(void){
    Serial.println("Thread Created");
    (*Operator::pattern)();
}

void Operator::processColor(String code)
{
  String red = code.substring(1,4);

  String green = code.substring(4,7);

  String blue = code.substring(7,10);

  Patterns::r = red.toInt();
  Patterns::g = green.toInt();
  Patterns::b = blue.toInt();
}

void Operator::processStaticPattern(String code)
{
  int pattern_num = code.substring(2,10).toInt();
  Serial.println(pattern_num);
  switch (pattern_num)
  {
    case 0:
      
      pattern = &Patterns::Solid_Color;
      Serial.println("Solid Color Selected");
      break;
    case 1:
      Serial.println("Color Cylce Selected");
      pattern = &Patterns::Color_Cycle;
      break;
    case 2:
      Serial.println("Rainbow Selected");
      pattern = &Patterns::Rainbow;
      break;
    default:
      pattern = &Patterns::Solid_Color;
      break;
  }
}

void Operator::processMusicPattern(String code)
{
  int pattern_num = code.substring(2,10).toInt();

  switch (pattern_num)
  {
    case 0:
      pattern = &Patterns::Simple_Music;
      break;
    default:
      pattern = &Patterns::Simple_Music;
      break;
  }
}