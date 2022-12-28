
#include <Wire.h>
#include "Screen.h"
#include <DFRobot_RGBLCD1602.h>

//Set up LCD  ========================================================
DFRobot_RGBLCD1602 lcd(16, 2);  // (collumns, rows)


bool power = true;

// Board Stuff =======================================================
void setup() {
  //Joystick Startup
  Serial1.begin(115200);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);

  //LCD Startup
  lcd.init();
  lcd.setRGB(0, 0, 255);
  lcd.print("Weclome to LED ");
  lcd.setCursor(1, 1);
  lcd.print("Controller");
  delay(3000);
  lcd.clear();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  //Initialize Selectables
  FuncSelectable Red("Red            ", RedPtr);
  FuncSelectable Orange("Orange         ", OrangePtr);
  FuncSelectable Yellow("Yellow         ", YellowPtr);
  FuncSelectable Green("Green          ", GreenPtr);
  FuncSelectable Blue("Blue           ", BluePtr);
  FuncSelectable Indigo("Indigo         ", IndigoPtr);
  FuncSelectable Violet("Violet         ", VioletPtr);
}

void loop() {
}
// End Board Stuff ====================================================
