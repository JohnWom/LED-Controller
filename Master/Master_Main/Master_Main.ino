#include "Operator.h"
#include "Function.h"

// Cursor Symbol
byte cursor_symbol[8] {
      0b00000,
      0b01000,
      0b00100,
      0b00010,
      0b00001,
      0b00010,
      0b00100,
      0b01000
    };


// Initialize Selectables
Selectable Red;
Selectable Orange;
Selectable Yellow;
Selectable Green;
Selectable Blue;
Selectable Indigo;
Selectable Violet;
Selectable Solid;
Selectable Fishpole;
Selectable Rainbow;
Selectable SimpleMusic;
Selectable Guitar;

Selectable toColors;
Selectable toPatterns;
Selectable toMusic;
Selectable toStatic;
Selectable backColor;
Selectable backMusic;
Selectable backStatic;
Selectable backPattern;

//Initialize Screens
Screen Home(&toColors, &toPatterns);
Screen Patterns(&backPattern, &toMusic);
Screen Music(&backMusic, &SimpleMusic);
Screen Static(&backStatic, &Solid);
Screen Color(&backColor, &Red);

//Initialize LCD
DFRobot_RGBLCD1602 lcd(16, 2);

//Initialize Operator
Operator Op(&Home, &lcd);



// Board Stuff =======================================================
void setup() {
  //Joystick Startup
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);

  //LCD Startup
  Serial.println("Starting LCD");
  
  lcd.init();
  lcd.customSymbol(0, cursor_symbol);
  delay(3000);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
 
  
  //create Function Pointers
  /*
  funcptr powerPtr = &powerToggle;
  
  funcptr RedPtr = &setColorRed;
  funcptr OrangePtr = &setColorOrange;
  funcptr YellowPtr = &setColorYellow;
  funcptr GreenPtr = &setColorGreen;
  funcptr BluePtr = &setColorBlue;
  funcptr IndigoPtr = &setColorIndigo;
  funcptr VioletPtr = &setColorViolet;

  funcptr SolidPtr = &setSolid;
  funcptr FishpolePtr = &setFishpole;
  funcptr RainbowPtr = &setRainbow;
  funcptr SimpleMusicPtr = &setSimpleMusic;
  */
  //Initialize Function Selectables
  
  Red.text = "Red            ";
  Red.functpoint = &setColorRed;

  Orange.text = "Orange         ";
  Orange.functpoint = &setColorOrange;
  
  Yellow.text = "Yellow         ";
  Yellow.functpoint = &setColorYellow;

  Green.text = "Green          ";
  Green.functpoint = &setColorGreen;

  Blue.text = "Blue           ";
  Blue.functpoint = &setColorBlue;

  Indigo.text = "Indigo         ";
  Indigo.functpoint = &setColorIndigo;

  Violet.text = "Violet         ";
  Violet.functpoint = &setColorViolet;

  Solid.text = "Solid          ";
  Solid.functpoint = &setSolid;

  Fishpole.text = "Fishpole       ";
  Fishpole.functpoint = &setFishpole;
  
  Rainbow.text = "Rainbow        ";
  Rainbow.functpoint = &setRainbow;

  SimpleMusic.text = "Simple Music   ";
  SimpleMusic.functpoint = &setSimpleMusic;

  Guitar.text = "Guitar         ";
  Guitar.functpoint = &setGuitar;

  //Initialize Pointer Selectables
  toColors.text = "Colors         ";

  toPatterns.text = "Patterns       ";

  toMusic.text = "Music Patterns ";

  toStatic.text = "Static Patterns";

  backColor.text = "back           ";

  backMusic.text = "back           ";

  backStatic.text = "back           ";

  backPattern.text = "back           ";

  //Create Selectable Loops
  backColor.next = &Red;
  Red.next = &Orange;
  Red.prev = &backColor;
  Orange.next = &Yellow;
  Orange.prev = &Red;
  Yellow.next = &Green;
  Yellow.prev = &Orange;
  Green.next = &Blue;
  Green.prev = &Yellow;
  Blue.next = &Indigo;
  Blue.prev = &Green;
  Indigo.next = &Violet;
  Indigo.prev = &Blue;
  Violet.prev = &Indigo;
  

  backMusic.next = &SimpleMusic;
  SimpleMusic.prev = &backMusic;
  SimpleMusic.next = &Guitar;
  Guitar.prev = &SimpleMusic;

  backStatic.next = &Solid;
  Solid.next = &Fishpole;
  Solid.prev = &backStatic;
  Fishpole.next = &Rainbow;
  Fishpole.prev = &Solid;
  Rainbow.prev = &Fishpole;

  backPattern.next = &toMusic;
  toMusic.next = &toStatic;
  toMusic.prev = &backPattern;
  toStatic.prev = &toMusic;

  toPatterns.prev = &toColors;
  toColors.next = &toPatterns;

  //Set Screen Pointers to Screens
  toColors.next_screen = &Color;
  toPatterns.next_screen = &Patterns;
  toMusic.next_screen = &Music;
  toStatic.next_screen = &Static;
  backColor.next_screen = &Home;
  backMusic.next_screen = &Patterns;
  backStatic.next_screen = &Patterns;
  backPattern.next_screen = &Home;

  //Initialize Operator
  

  // Log
  Serial.println("Finshed Boot-Up");
  Op.draw();
  lcd.setCursor(0, 0);
  lcd.write((unsigned char)0);
}

void loop() {
  
  Op.joystick_readings();
}
// End Board Stuff ====================================================
