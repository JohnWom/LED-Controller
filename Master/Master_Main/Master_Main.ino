#include "Operator.h"
#include "Function.h"

Operator Op;

byte cursor_symbol[8] {
      0b00000,
      0b01000,
      0b00100,
      0b00010,
      0b00001,
      0b00010,
      0b00100,
      0b01000,
    };

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
  DFRobot_RGBLCD1602 lcd(16, 2);
  lcd.init();
  lcd.customSymbol(0, cursor_symbol);
  delay(3000);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
 
  
  //create Function Pointers
  funcptr powerPtr = powerToggle;

  funcptr RedPtr = &setColorRed;
  funcptr OrangePtr = &setColorOrange;
  funcptr YellowPtr = &setColorYellow;
  funcptr GreenPtr = &setColorGreen;
  funcptr BluePtr = &setColorBlue;
  funcptr IndigoPtr = &setColorIndigo;
  funcptr VioletPtr = &setColorViolet;

  funcptr SolidPtr = setSolid;
  funcptr FishpolePtr = setFishpole;
  funcptr RainbowPtr = setRainbow;
  funcptr SimpleMusicPtr = setSimpleMusic;

  //Initialize Function Selectables
  Selectable Red;
  Red.text = "Red            ";
  Red.functpoint = RedPtr;

  Selectable Orange;
  Orange.text = "Orange         ";
  Orange.functpoint = OrangePtr;
  
  Selectable Yellow;
  Yellow.text = "Yellow         ";
  Yellow.functpoint = YellowPtr;

  Selectable Green;
  Green.text = "Green          ";
  Green.functpoint = GreenPtr;

  Selectable Blue;
  Blue.text = "Blue           ";
  Blue.functpoint = BluePtr;

  Selectable Indigo;
  Indigo.text = "Indigo         ";
  Indigo.functpoint = IndigoPtr;

  Selectable Violet;
  Violet.text = "Violet         ";
  Violet.functpoint = VioletPtr;

  Selectable Solid;
  Solid.text = "Solid          ";
  Solid.functpoint = SolidPtr;

  Selectable Fishpole;
  Fishpole.text = "Fishpole       ";
  Fishpole.functpoint = FishpolePtr;
  
  Selectable Rainbow;
  Rainbow.text = "Rainbow        ";
  Rainbow.functpoint = RainbowPtr;

  Selectable SimpleMusic;
  SimpleMusic.text = "Simple Music   ";
  SimpleMusic.functpoint = SimpleMusicPtr;

  //Initialize Pointer Selectables
  Selectable toColors;
  toColors.text = "Colors         ";

  Selectable toPatterns;
  toPatterns.text = "Patterns       ";

  Selectable toMusic;
  toMusic.text = "Music Patterns ";

  Selectable toStatic;
  toStatic.text = "Static Patterns";

  Selectable backColor;
  backColor.text = "back           ";

  Selectable backMusic;
  backMusic.text = "back           ";

  Selectable backStatic;
  backStatic.text = "back           ";

  Selectable backPattern;
  backPattern.text = "back           ";

  //Create Selectable Loops
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
  Violet.next = &backColor;
  Violet.prev = &Indigo;
  backColor.next = &Red;
  backColor.prev = &Violet;

  backMusic.next = &SimpleMusic;
  backMusic.prev = &SimpleMusic;
  SimpleMusic.next = &backMusic;
  SimpleMusic.prev = &backMusic;

  backStatic.next = &Solid;
  backStatic.prev = &Rainbow;
  Solid.next = &Fishpole;
  Solid.prev = &backStatic;
  Fishpole.next = &Rainbow;
  Fishpole.prev = &Solid;
  Rainbow.next = &backStatic;
  Rainbow.prev = &Fishpole;

  backPattern.next = &toMusic;
  backPattern.prev = &toStatic;
  toMusic.next = &toStatic;
  toMusic.prev = &backPattern;
  toStatic.next = &backPattern;
  toStatic.prev = &toMusic;

  toPatterns.next = &toColors;
  toPatterns.prev = &toColors;
  toColors.next = &toPatterns;
  toColors.prev = &toPatterns;

  //Initialize Screens
  Screen Home(&toColors, &toPatterns);
  Screen Patterns(&toStatic, &toMusic);
  Screen Music(&backMusic, &SimpleMusic);
  Screen Static(&backStatic, &Solid);
  Screen Color(&backColor, &Red);

  //Set Screen Pointers to Screens
  toColors.next_screen = &Color;
  toPatterns.next_screen = &Patterns;
  toMusic.next_screen = &Music;
  toStatic.next_screen = &Static;
  backColor.next_screen = &Home;
  backMusic.next_screen = &Home;
  backStatic.next_screen = &Patterns;
  backPattern.next_screen = &Patterns;

  //Initialize Operator
  Operator Op(&Home, &lcd);

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
