#include "Screen.h"

class Quadrant
{
private:
  class *adj1;
  class *adj2;

  char last_text[8] = '        ';
  int start_x;
  int start_y;

  class friend Screen;

public:
  Quadrant(int x, int y) {
    start_x = x;
    start_y = y;
  }

  writeText(char text[8]) {
    for (int i = 0; i < 8; i++) { // If one character in the string 
      if (text[i] != last) {      // is not the same, update the display
        setCursor(start_x,start_y);
        lcd.print(text);
      break;
      }
    }
  }


class Cursor 
{
private:
  class Quadrant* cursor_location;

  class friend Screen;

public:
  void moveCursorAdj1(); // Moves Cursor to Adj1
  void moveCursorAdj2(){
    cursor_location ==
  }

}

class Screen {

public:
  void Write_Text(char text, )



private:
  void setup(){
    Quadrant TopLeft(0,0);
    Quadrant TopRight(7,0);
    Quadrant BottomLeft(0,1);
    Quadrant BottomRight(7,1);

    TopLeft.adj1 = *TopRight;
    TopLeft.adj2 = *BottomLeft;

    TopRight.adj1 = *TopLeft;
    TopRight.adj2 = *BottomRight;

    BottomLeft.adj1 = *BottomRight;
    BottomLeft.adj2 = *TopLeft;

    BottomRight.adj1 = *BottomLeft;
    BottomRight.adj2 = *TopRight;
  }

  ~Screen(){
    delete TopLeft;
    delete TopRight;
    delete BottomLeft;
    delete BottomRight;
  }
}