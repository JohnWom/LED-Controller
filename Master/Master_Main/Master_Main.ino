
#include <Wire.h>
#include "Screen.h"
#include <DFRobot_RGBLCD1602.h>

//Set up LCD  ========================================================
DFRobot_RGBLCD1602 lcd(16, 2);  // (collumns, rows)


bool power = true;

// Board Stuff =======================================================
void setup() {
  //Joystick Startup
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);

  //LCD Startup
  Serial.println("Starting LCD")
  lcd.init();
  lcd.setRGB(0, 0, 255);
  lcd.print("Weclome to LED ");
  lcd.setCursor(1, 1);
  lcd.print("Controller");
  delay(3000);
  lcd.clear();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  // Log
  Serial.println("Creating Menu Framework")
  lcd.setCursor(0, 0);
  lcd.print("Starting Up    ");
  lcd.setCursor(0, 0);
  lcd.print("               ");

  //Initialize Function Selectables
  FuncSelectable Red("Red            ", RedPtr);
  FuncSelectable Orange("Orange         ", OrangePtr);
  FuncSelectable Yellow("Yellow         ", YellowPtr);
  FuncSelectable Green("Green          ", GreenPtr);
  FuncSelectable Blue("Blue           ", BluePtr);
  FuncSelectable Indigo("Indigo         ", IndigoPtr);
  FuncSelectable Violet("Violet         ", VioletPtr);

  FuncSelectable Solid("Solid          ", SolidPtr);
  FuncSelectable Fishpole("Fishpole       ", FishpolePtr);
  FuncSelectable Rainbow("Rainbow        ", RainbowPtr);

  FuncSelectable SimpleMusic("Simple Music   ", setSimpleMusic)

  //Initialize Pointer Selectables
  ScreenSelectable toColors("Colors         ");
  ScreenSelectable toPatterns("Patterns       ");
  ScreenSelectable toMusic("Music Patterns ");
  ScreenSelectable toStatic("Static Patterns");
  ScreenSelectable backColor("back           ");
  ScreenSelectable backMusic("back           ");
  ScreenSelectable backStatic("back           ");
  ScreenSelectable backPattern("back           ");

  //CreateSelectablePointers
  ScreenSelectable *ptrRed = &Red;
  ScreenSelectable *ptrOrange = &Orange;
  ScreenSelectable *ptrYellow = &Yellow;
  ScreenSelectable *ptrGreen = &Green;
  ScreenSelectable *ptrBlue = &Blue;
  ScreenSelectable *ptrIndigo = &Indigo;
  ScreenSelectable *ptrViolet = &Violet;

  ScreenSelectable *ptrtoColors = &toColors;
  ScreenSelectable *ptrtoPatterns = &toPatterns;
  ScreenSelectable *ptrtoMusic = &toMusic;
  ScreenSelectable *ptrtoStatic = &toStatic;
  ScreenSelectable *ptrbackColor = &backColor;
  ScreenSelectable *ptrbackMusic = &backMusic;
  ScreenSelectable *ptrbackStatic = &backStatic;
  ScreenSelectable *ptrbackPattern = &backPattern;

  ScreenSelectable *ptrSolid = &Solid;
  ScreenSelectable *ptrFishpole = &Fishpole;
  ScreenSelectable *ptrRainbow = &Rainbow;

  ScreenSelectable *ptrSimpleMusic = &SimpleMusic;

  //Create Selectable Loops
  Red.setNext(ptrOrange);
  Red.setPrev(ptrbackColor);
  Orange.setNext(ptrYellow);
  Orange.setPrev(ptrRed);
  Yellow.setNext(ptrGreen);
  Yellow.setPrev(ptrOrange);
  Green.setNext(ptrBlue);
  Green.setPrev(ptrYellow);
  Blue.setNext(ptrIndigo);
  Blue.setPrev(ptrGreen);
  Indigo.setNext(ptrViolet);
  Indigo.setPrev(ptrBlue);
  Violet.setNext(ptrbackColor);
  Violet.setPrev(ptrIndigo);
  backColor.setNext(ptrRed);
  backColor.setPrev(ptrViolet);

  backMusic.setNext(ptrSimpleMusic);
  backMusic.setPrev(ptrSimpleMusic);
  SimpleMusic.setNext(ptrbackMusic);
  SimpleMusic.setPrev(ptrbackMusic);

  backStatic.setNext(ptrSolid);
  backStatic.setPrev(ptrRainbow);
  Solid.setNext(ptrFishpole);
  Solid.setPrev(ptrbackStatic);
  Fishpole.setNext(ptrRainbow);
  Fishpole.setPrev(ptrSolid);
  Rainbow.setNext(ptrbackStatic);
  Rainbow.setPrev(ptrFishpole);

  backPattern.setNext(ptrtoMusic);
  backPattern.setPrev(ptrtoStatic);
  toMusic.setNext(ptrtoStatic);
  toMusic.setPrev(ptrbackPattern);
  toStatic.setNext(ptrbackPattern);
  toStatic.setPrev(ptrtoMusic);

  toPatterns.setNext(ptrtoColors);
  toPatterns.setPrev(ptrtoColors);
  toColors.setNext(ptrtoPatterns);
  toColors.setPrev(ptrtoPatterns);    

  //Initialize Screens
  Screen Home(ptrtoColors, ptrtoPatterns);
  Screen Patterns(ptrtoStatic, ptrtoMusic);
  Screen Music(ptrbackMusic, ptrSimpleMusic);
  Screen Static(ptrbackStatic, ptrSolid);
  Screen Color(ptrbackColor, ptrRed);

  //Create Screen Pointers
  Screen *ptrHome = &Home;
  Screen *ptrPatterns = &Patterns;
  Screen *ptrMusic = &Music;
  Screen *ptrStatic = &Static;
  Screen *ptrColor = &Color;

  //Set Screen Pointers to Screens
  toColors.setScreen(ptrColor);
  toPatterns.setScreen(ptrPatterns);
  toMusic.setScreen(ptrMusic);
  toStatic.setScreen(ptrStatic);
  backColor.setScreen(ptrHome);
  backMusic.setScreen(ptrHome);
  backStatic.setScreen(ptrPatterns);
  backPattern.setScreen(ptrPatterns);

  //Initialize Operator
  Operator Operator(ptrHome);
  Operator.draw();
}

void loop() {
}
// End Board Stuff ====================================================
