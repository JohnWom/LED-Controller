#include "Function.h"
#include "Operator.h"

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

  FuncSelectable SimpleMusic("Simple Music   ", SimpleMusicPtr);

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
 Selectable *ptrRed = &Red;
 Selectable *ptrOrange = &Orange;
 Selectable *ptrYellow = &Yellow;
 Selectable *ptrGreen = &Green;
 Selectable *ptrBlue = &Blue;
 Selectable *ptrIndigo = &Indigo;
 Selectable *ptrViolet = &Violet;

 Selectable *ptrtoColors = &toColors;
 Selectable *ptrtoPatterns = &toPatterns;
 Selectable *ptrtoMusic = &toMusic;
 Selectable *ptrtoStatic = &toStatic;
 Selectable *ptrbackColor = &backColor;
 Selectable *ptrbackMusic = &backMusic;
 Selectable *ptrbackStatic = &backStatic;
 Selectable *ptrbackPattern = &backPattern;

 Selectable *ptrSolid = &Solid;
 Selectable *ptrFishpole = &Fishpole;
 Selectable *ptrRainbow = &Rainbow;

 Selectable *ptrSimpleMusic = &SimpleMusic;

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
  Operator Op(ptrHome);


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
  delay(3000);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  // Log
  Serial.println("Finshed Boot-Up");

}

void loop() {
 Op.joystick_readings();
}
// End Board Stuff ====================================================
