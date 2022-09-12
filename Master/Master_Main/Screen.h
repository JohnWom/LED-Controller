#ifndef SCREEN.H
#define SCREEN .H

#include <DFRobot_RGBLCD1602.h>

class Quadrant
{
private:
// Who's Next Door - For easy moving of cursor
  class Quadrant* adj1; 
  class Quadrant* adj2;

  char last_text[8] = '        '; // Text that is Displayed in Quadrant

// Coordinates for start of quadrant - for writing text
  int start_x; 
  int start_y;

public:
  Quadrant(int, int); // Paramatized Initializer

  writeText(char text[8]); // Writes 8 characters to 

class Cursor {

private:
  class Quadrant* cursor_location;

public:
  void moveCursorAdj1(); // Moves Cursor to Adj1
  void moveCursorAdj2(); // Moves Cursor to Adj2
}

class Screen {

public:
  void Write_Text(char text[8]); // Writes a Text on a Specific Quadrant



private:
  void setup(); // Creates 4 Quadrands

  ~Screen(); // Deconstructor
}


#endif