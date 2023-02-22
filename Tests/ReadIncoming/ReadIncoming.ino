#include <string.h>
String input;

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
