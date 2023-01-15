#include "Operator.h"


Operator::Operator(Screen* s){
  current_screen = s;
}

void Operator::draw(){
  // Draw Top Text
  lcd.setCursor(1,0);
  lcd.print(current_screen->top_item->text);

  // Draw Bottom Text
  lcd.setCursor(1,1);
  lcd.print(current_screen->bottom_item->text)
}

void Operator::Upscroll(){
  int redraw = current_screen->scrollUp()
  if (redraw == 1) {draw();}
}

void Operator::Downscroll(){
  int redraw = current_screen->scrollDown()
  if (redraw == 1) {draw();}
}

void Operator::click(){
  Selectable* current;
  // Set current to item cursor is on
  if (current_screen->cursor_pos == 0) {
    current = current_screen->top_item;
  } else {
    current = current_screen->bottom_item;
  }

  // See if item has func or not
  if (typeid(*current).name() == "class FuncSelectable") {
    current->exec();
  }
  else if typeid(*current).name() == "class ScreenSelectable") {
    current_screen = current->nextScreen();
  }
}

// Read Joystick
void Operator::joystick_readings() {
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  int SW_state = digitalRead(SW);

  if (SW_state == 0) {
    click();
  }
      
  //Define mapY
  if (yPosition > 900) {
    Upscroll();
    }
  else if (yPosition < 150) {
    Downscroll();
  }
}