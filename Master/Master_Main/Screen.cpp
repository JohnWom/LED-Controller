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

  void writeOnQuadrant(char text[]) {
    lcd.setCursor(start_x, start_y)
  } 
}

class Cursor {
  
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