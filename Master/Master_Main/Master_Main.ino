
#include <Wire.h>
#include <DFRobot_RGBLCD1602.h>
#include "Menu_Tree.h"
//Set up LCD  ========================================================
DFRobot_RGBLCD1602 lcd( 6, 2); // (collumns, rows)

//Set up Joystick ====================================================
int VRx = A3;     //X direction analog pin
int VRy = A2;     //Y direction analog pin
int SW = 4;      //Button/Click Digital Pin

//int xPosition = 0;
//int yPosition = 0;
int SW_state = 1;
int mapX = 0;
int mapY = 0;

//Set up Switches ===================================================
int old_pattern = 0;
int old_colornum = 0;
int pattern = 1;
int colornum = 1;

bool mode = false;
bool power = true;
//Function Prototypes ===============================================

void joystickReadings(); //Updates Readings on Joystick

void updateDisplay(char, int); //Updates Display (text, k) - k is pattern or color

void xFunction(); //Controls in X axis

void yFunction(); //Controls in Y axis

void button(); //Controls Button

void PowerToggle(); // Turns Power On/Off

void colorFunction(int); //Cycles through different colors

void patternFunction(int); //Cycles through different pattern functions

// Board Stuff =======================================================
void setup() {
//Joystick Startup
  Serial1.begin(115200);
  pinMode(VRx,INPUT);
  pinMode(VRy,INPUT);
  pinMode(SW,INPUT_PULLUP);
  
//LCD Startup
  lcd.init();
  lcd.setRGB(0,0,255);
  lcd.print("Weclome to LED ");
  lcd.setCursor(1,1);
  lcd.print("Controller");
  delay(3000);
  lcd.clear();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  joystickReadings();
  xFunction();
  yFunction();
  colorFunction(colornum);
  patternFunction(pattern);
  button();
  //PowerToggle();
}
// End Board Stuff ====================================================


// joystickReadings() - Processes Joystick and Button =================
// Left+/Right    Up+/Down    On1/Off
void joystickReadings() {
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  //Serial.println(SW_state);

  //Define mapX
  if (xPosition > 900) {mapX = 1;}
  else if (xPosition < 150) {mapX = -1;}
  else {mapX = 0;}
  
  //Define mapY
  if (yPosition > 900) {mapY = 1;}
  else if (yPosition < 150) {mapY = -1;}
  else {mapY = 0;}
  
  delay(100);
}

// updateDisplay() - Updates the display ==============================
void UpdateDisplay( char text[], int k) {
  //lcd.clear();
  if (pattern != old_pattern && k == 1) {
    for (int i = 0; i <16; i++) {
      lcd.setCursor(i, 1);
      lcd.print(' ');
    }
    lcd.setCursor(0,1);
    lcd.print(text);
    old_pattern = pattern;
    }
  if (colornum != old_colornum && k == 0) {
    for (int i = 0; i <16; i++) {
      lcd.setCursor(i, 0);
      lcd.print(' ');
    }
    lcd.home();
    lcd.print(text);
    old_colornum = colornum;
  }
}

// xFunction() - controls joystick in the x direction =================
void xFunction() {
  if (mapX == 1) {
    pattern++;
    Serial1.println('&');
    Serial.println('&');
  }
  else if (mapX == -1) {
    pattern--;
    Serial1.println('*');
  }
  if (pattern < 0) {pattern = 1;}
  else if (pattern > 1) {pattern = 0;}
}
 
// yFunction() - controls joystick in the y direction =================
// y direction is changes in color
void yFunction() {
  if (mapY == 1) {
    colornum++;
    Serial1.println('!');
  }
  else if (mapY == -1) {
    colornum--;
    Serial1.println('@');
  }
  if (colornum<0) {colornum = 8;}
  else if (colornum > 8) {colornum = 0;}
}

// button() - controls joystick button ================================
void button() {
  //Serial.println(SW_state);
  if (SW_state != 1) {
    //UpdateDisplay("Button Pressed!",0,0);
    lcd.setCursor(0,0);
    delay(300);
    SW_state = digitalRead(SW);
    if (SW_state != 1) {
      delay(700);
      SW_state = digitalRead(SW);
      if (SW_state != 1){
        delay(2000);
        SW_state = digitalRead(SW);
        if (SW_state != 1) {
          Serial1.println('#');
          lcd.clear();
          lcd.print("Power Toggle!");
          power = !power;
          delay(500);
          }
        else {mode = !mode; Serial1.println('$');lcd.clear();lcd.print("Music Toggle!");delay(300);}
      }
      else {mode = !mode; Serial1.println('$');lcd.clear();lcd.print("Music Toggle!");delay(300);}
    }
    else {mode = !mode; Serial1.println('$');lcd.clear();lcd.print("Music Toggle!");delay(300);}
  }
}

// PowerToggle() ==========================================================
void PowerToggle() {
  long old_time = millis();
  while ( !power ) {
    SW_state = digitalRead(SW);
    if (SW_state = 1 && old_time > 500) {
      power = !power;
      Serial1.println("#");
    }
    }
}

// colorFunction() - cycles through different colors ==================
void colorFunction(int colornum) {
  switch (colornum) {
    case 0: //Red
      //r = 128; g = 0; b = 0;
      UpdateDisplay("Color: Red", 0);
      break;
    case 1: //Orange
      //r = 255, g = 100; b =0;
      UpdateDisplay("Color: Orange", 0);
      break;
    case 2: //Yellow
      //r = 255; g = 255; b = 0;
      UpdateDisplay("Color: Yellow", 0);
      break;
    case 3: //Green
      //r = 0; g = 128; b = 0;
      UpdateDisplay("Color: Green", 0);
      break;
    case 4: //Blue
      //r = 0; g = 0; b = 205;
      UpdateDisplay("Color: Blue", 0);
      break;
    case 5: //Indigo
      //r = 75; g = 0; b = 130;
      UpdateDisplay("Color: Indigo", 0);
      break;
    case 6: //Purple
      //r = 128; g = 0; b = 128;
      UpdateDisplay("Color: Purple", 0);
      break;
    case 7: //White
      //r = 255; g = 255; b = 255;
      UpdateDisplay("Color: White", 0);
      break;
    case 8: //Black
      //r = 0; g = 0; b = 0;
      UpdateDisplay("Color: Black", 0);
      break;
    default:
      //r = 0; g = 128; b = 128;
      UpdateDisplay("Color: Default", 0);
      break;
  }
}

// patternFunction() - cycles through different patterns ==============
void patternFunction(int pattern) {
  if (!mode) {  // Static Mode
    switch (pattern) {
      case 0: //Solid
        UpdateDisplay("Pattern: Solid", 1);
        break;
      case 1: //Led Off
        UpdateDisplay("Pattern: Cycler", 1);
        break;
      default:
        UpdateDisplay("Pattern: Default", 1);
        break;
    }
  }
  if (mode) {  // Music Mode
    switch (pattern) {
      case 0: //Solid
        UpdateDisplay("Pattern: Bass", 1);
        break;
      case 1: //Led Off
        UpdateDisplay("Pattern: Off", 1);
        break;
      default:
        UpdateDisplay("Pattern: Bass", 1);
        break;
    }
  }
}
