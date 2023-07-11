#include "Function.h"

// Core Functions ----------------------------------
void powerToggle(){
  Serial1.println("0000000000");
}

// Color Functions ---------------------------------
void setColorRed(){
  Serial1.println("C255000000");
}

void setColorOrange(){
  Serial1.println("C255135000");
}

void setColorYellow(){
  Serial1.println("C255255000");
}

void setColorGreen(){
  Serial1.println("C000200000");
}

void setColorBlue(){
  Serial1.println("C000000200");
}

void setColorIndigo(){
  Serial1.println("C060000255");
}

void setColorViolet(){
  Serial1.println("C140000255");
}

// Pattern Functions --------------------------------
void setSolid(){
  Serial1.println("SP00000000");
}

void setParty1(){
  Serial1.println("SP00000001");
}

void setParty2(){
  Serial1.println("SP00000002");
}



void setSimpleMusic(){
  Serial1.println("MP00000000");
}

void setGuitar(){
  Serial1.println("MP00000001");
}


