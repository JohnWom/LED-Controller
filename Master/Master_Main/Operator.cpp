#include "Operator.h"


Operator::Operator(Screen* s, DFRobot_RGBLCD1602* d) {
  // (collumns, rows)
  current_screen = s;
  display = d;
  cursor_position = 0;
}

void Operator::draw() {
  Serial.println("Drawing...");
 
  display->setCursor(1, 0);
  display->print(current_screen->top_item->text);

  display->setCursor(1, 1);
  display->print(current_screen->bottom_item->text);
  Serial.println("Drawing Done");
}

void Operator::draw_cursor() {
  display->setCursor(0, cursor_position);
  display->write((unsigned char)0);
  // Clear other cursor
  if (cursor_position) {
    display->setCursor(0, 0);
    display->print(" ");    
  }
  else {
    display->setCursor(0, 1);
    display->print(" ");
  }
  
}

void Operator::Upscroll() {
  if (cursor_position == 0) { 
    // Roll Options
    current_screen->scrollUp();
    draw();
   }
  else {
    cursor_position = 0;
    draw_cursor();
    Serial.println("Cursor Drawn");
  }
}

void Operator::Downscroll() {
  if (cursor_position == 1) { 
      current_screen->scrollDown();
      draw(); 
    }
    else {
    cursor_position = 1;
    draw_cursor();
    Serial.println("Cursor Drawn");
  }
}

void Operator::click() {
  Selectable* current;
  // Set current to item cursor is on
  if (cursor_position == 0) {
    current = current_screen->top_item;
  } else {
    current = current_screen->bottom_item;
  }

  // execute both, one will be undefined
  if (current->next_screen == NULL)
    (*current->functpoint)();
  else  {
    current_screen = current->next_screen;
  }
}

// Read Joystick
void Operator::joystick_readings() {
  int yPosition = analogRead(VRy);
  //int yPosition = analogRead(VRy);
  int SW_state = digitalRead(SW);

  if (SW_state == 0) {
    Serial.print("Button Clicked!");
    click();
    draw();
  }
  //Define mapY
  if (yPosition > 910) {
    Upscroll();
    Serial.println("Scrolled Up");
    delay(200);
  } else if (yPosition < 150) {
    Downscroll();
    Serial.println("Scrolled Down");
    delay(200);
  }
}