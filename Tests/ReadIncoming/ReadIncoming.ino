#include <string.h>
String input;

//======================================================================
//  This program is meant to allow user to read commands coming into
//  the terminal, and print the command to the computer Serial Monitor
//
//  Serial is the serial that connects to the computer
//   
//  Serial1 is the serial that connects to the master chip
//
//======================================================================
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available()) {
    input = Serial1.readString();
    input.trim();
    Serial.println(input);
  }
}
