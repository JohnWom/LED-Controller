#include "Operator.h"


Operator::Operator()
{
  pattern = &Patterns::Solid_Color;
  t = new Thread;
  t->start(mbed::callback(Operator::runPattern));
}

void Operator::readSerial() 
{
  String code;

  if (Serial1.available()) {
    code = Serial1.readString();
    code.trim();

    // display the code
    Serial.println(code);
    
    // stop thread running old pattern
    t->terminate();
    t = new Thread;

    // make the change
    if (code.charAt(0) == 'C')
      processColor(code);
    else if (code.charAt(0) == 'M')
      processMusicPattern(code);
    else if (code.charAt(0) == 'S')
      processStaticPattern(code);

    // restsart the thread with the new changes
    t->start(mbed::callback(Operator::runPattern));
  }
}

void Operator::runPattern(void){
  // Wrapper function for pattern pointer
    (*Operator::pattern)();
}

void Operator::processColor(String code)
{
  // decode code into RGB values
  String red = code.substring(1,4);

  String green = code.substring(4,7);

  String blue = code.substring(7,10);

  Patterns::r = red.toInt();
  Patterns::g = green.toInt();
  Patterns::b = blue.toInt();
}

void Operator::processStaticPattern(String code)
{ // Select pattern number from code
  int pattern_num = code.substring(2,10).toInt();

  // change the pattern, confirm change in terminal  
  switch (pattern_num)
  {
    case 0:   
      pattern = &Patterns::Solid_Color;
      Serial.println("Solid Color Selected");
      break;
    case 1:
      pattern = &Patterns::Color_Cycle;
      Serial.println("Color Cylce Selected");
      break;
    case 2:
      pattern = &Patterns::Rainbow;
      Serial.println("Rainbow Selected");
      break;
    default:
      pattern = &Patterns::Solid_Color;
      Serial.println("Default Solid Selected");
      break;
  }
}

void Operator::processMusicPattern(String code)
{ // Select Pattern number from code
  int pattern_num = code.substring(2,10).toInt();

  // change the pattern, confirm change in terminal 
  switch (pattern_num)
  {
    case 0:
      pattern = &Patterns::Simple_Music;
      Serial.println("Simple Music Selected");
      break;
    case 1:
      pattern = &Patterns::Guitar;
      Serial.println("Guitar Selected");
      break;
    default:
      pattern = &Patterns::Simple_Music;
      Serial.println("Default Simple Music Selected");
      break;
  }
}