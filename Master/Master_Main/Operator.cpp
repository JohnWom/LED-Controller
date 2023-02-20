#include "Operator.h"


Operator::Operator(Screen* s, DFRobot_RGBLCD1602* d) {
  // (collumns, rows)
  current_screen = s;
  display = d;
  
}

void Operator::draw() {
  Serial.println("Drawing...");
 
  display->setCursor(1, 0);
  display->print(current_screen->top_item->text);

  display->setCursor(1, 1);
  display->print(current_screen->bottom_item->text);
  Serial.println("Drawing Done");
}

void Operator::Upscroll() {
  int redraw = current_screen->scrollUp();
  if (redraw == 1) { draw(); }
  else {
    display->setCursor(0, 0);
    display->write((unsigned char)0);
  }
}

void Operator::Downscroll() {
  int redraw = current_screen->scrollDown();
  if (redraw == 1) { draw(); }
    else {
    display->setCursor(0, 1);
    display->write((unsigned char)0);
  }
}

void Operator::click() {
  Selectable* current;
  // Set current to item cursor is on
  if (current_screen->cursor_pos == 0) {
    current = current_screen->top_item;
  } else {
    current = current_screen->bottom_item;
  }

  // execute both, one will be undefined
  current->exec();
  if (current->nextScreen()) {
    current_screen = current->nextScreen();
  }
}

// Read Joystick
void Operator::joystick_readings() {
  int xPosition = analogRead(VRx);
  //int yPosition = analogRead(VRy);
  int SW_state = digitalRead(SW);
  Serial.println(xPosition);
  if (SW_state == 0) {
    click();
  }

  //Define mapY
  if (xPosition > 910) {
    Upscroll();
  } else if (xPosition < 150) {
    Downscroll();
  }
}