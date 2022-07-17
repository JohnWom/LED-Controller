#include "patterns.h"
const int LedPin = 25;
#include "patterns.h"

#define MAX_PATTERNS 3
#define MAX_COLORS 8
//Setup for Led Control

int r = 0;
int g = 128;
int b = 128;

char input = 'a';


int colornum = 1;
int pattern = 1;
bool mode = false;
bool power = true;

// Control Function Prototypes ==================================================

void readSerial();  //Reads Serial Communication

void PowerToggle(); //Controls System being on or off

void colorFunction(int); //Cycles through different colors

void patternFunction(int); //Cycles through different pattern functions


void setup() {
//Runs Once
    
    Serial.begin(115200);
    Serial1.begin(115200);
    Serial.println("Opening Serial ...");
    while(!Serial);

    Serial.println("Starting LEDS ... ");
    Led_Setup();
}

void loop() {
//Runs Repeatedly

    //Power Control
    readSerial();
    //PowerToggle();
    colorFunction(colornum);
    //Audio Processing
    /*if (mode) { //Only do this when in music mode
      sampler();
      FourierFunction();
      audio_analyzer();
    }*/
    
    //Pattern Calling
    patternFunction(pattern);
    
    Serial.print(colornum);
    Serial.println(pattern);

}

// Control Function Definitions ====================================================

void readSerial() {
  if (Serial1.available()) {
    input = Serial1.read();
    Serial.println(input);

    // Power
    if (input == '#') {power = !power;}

    // Color
    if (input == '!') {colornum++;}
    else if (input =='@') {colornum--;}
    if (colornum <  0) {colornum=MAX_COLORS;}
    else if (colornum > MAX_COLORS) {colornum=0;}

    // Mode
    if (input == '$') {mode = !mode;}
   

    // Pattern
    if (input == '&') {pattern++;}
    else if (input == '*') {pattern--;}
    if (pattern < 0) {pattern=MAX_PATTERNS;}
    else if (pattern > MAX_PATTERNS) {pattern=0;}
  }
}

void PowerToggle() {

  while (!power) {
    readSerial();
    r = 0; g = 0; b = 0;
    Solid_Color(r,g,b);
    Serial.print("Power Off");
    }
}

void colorFunction(int colornum) {
  switch (colornum) {
    case 0: {//Red
      r = 128; g = 0; b = 0;
      break;}
    case 1: {//Orange
      r = 255, g = 100; b =0;
      break;}
    case 2: {//Yellow
      r = 255; g = 255; b = 0;
      break;}
    case 3: {//Green
      r = 0; g = 128; b = 0;
      break;}
    case 4: {//Blue
      r = 0; g = 0; b = 205;
      break;}
    case 5: {//Indigo
      r = 75; g = 0; b = 130;
      break;}
    case 6: {//Purple
      r = 128; g = 0; b = 128;
      break;}
    case 7: {//White
    r = 255; g = 255; b = 255;
      break;}
    case 8: {//Black
      r = 0; g = 0; b = 0;
      break;}
    default: {
      r = 0; g = 128; b = 128;
      break;}
  }
}

// patternFunction() - cycles through different patterns ==============
void patternFunction(int pat) {
  if (mode != true) { //Static Mode
    switch (pat) {
      case 0: {//Solid
        Solid_Color(r,g,b);
        break; }
      case 1: {//Led Off
        Color_Cycle(r, g, b);
        break;}
      default: {
        Solid_Color(r,g,b);
        break; }
    }
  }
  if (mode) { //Music Mode
    switch (pat) {
      case 0: {//Bass
        Solid_Color(r,g,b);
        break; }
      case 1: {//Led Off
        break;}
      default: {
        Bass(r,g,b);
        break;}
    }
  }
}
