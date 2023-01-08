#include "Screen.h"




class Screen
{
  public:
    // Default Parameterized Constructor
    Screen(Selectable* top, Selectable* bottom) {
      top_item = top;
      bottom_item = bottom;
      cursor_pos = 0;
    }

    // Scroll Up
    int scrollUp() {
      // If cursor is on lower item, just move it up
      if (cusor_pos == 1) {
        cursor_pos = 0;
        return 0;
      } else {  // Otherwise Rotate Items
        bottom_item = top_item;
        top_item = top_item->prev();
        return 1;
      }
    }

    // Scroll Down
    int scrollDown() {
      // If cursor is on top item, just move it down
      if (cusor_pos == 0) {
        cursor_pos = 1;
        return 0;
      } else {  // Otherwise Rotate Items
        top_item = bottom_item;
        bottom_item = bottom_item->next();
        return 1;
      }
    }
    }

  private:
    Selectable* top_item;
    Selectable* bottom_item;
    int cursor_pos;
};


class Operator
{
  public:

    Operator(Screen* s){
      current_screen = s;
    }

    // Draws text to Screen
    void draw(){
      // Draw Top Text
      lcd.setCursor(1,0);
      lcd.print(current_screen->top_item->text);

      // Draw Bottom Text
      lcd.setCursor(1,1);
      lcd.print(current_screen->bottom_item->text)
    }

    // Scrolls Up through screen options
    void Upscroll(){
      int redraw = current_screen->scrollUp()
      if (redraw == 1) {draw();}
    }

    // Scrolls Down through screen options
    void Downscroll(){
      int redraw = current_screen->scrollDown()
      if (redraw == 1) {draw();}
    }

    // Execute Command
    void click(){
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
    void joystick_readings() {
      int xPosition = analogRead(VRx);
      int yPosition = analogRead(VRy);
      int SW_state = digitalRead(SW);

      if (SW_state == 0) {
        click();
      }

      //Define mapX
      if (xPosition > 900) {mapX = 1;}
      else if (xPosition < 150) {mapX = -1;}
      else {mapX = 0;}
      
      //Define mapY
      if (yPosition > 900) {
        mapY = 1;
        Upscroll();
        }
      else if (yPosition < 150) {
        mapY = -1;
        Downscroll();
      }
      else {mapY = 0;}
    }

  private:
    Screen* current_screen;
};