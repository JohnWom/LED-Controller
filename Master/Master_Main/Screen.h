#ifndef SCREEN.H
#define SCREEN .H

class Quadrant
{
private:
// Who's Next Door - For easy moving of cursor
  class *adj1; 
  class *adj2;

  char last_text[8] = '        '; // Text that is Displayed in Quadrant

// Coordinates for start of quadrant - for writing text
  int start_x; 
  int start_y;

  class friend Screen;  // So that Screen can see Everything

public:
  Quadrant(int x, int y); // Paramatized Initializer

  void writeOnQuadrant(char text[]); // Writes Text Across the Quadrant (MAX 8 Characters)
}

class Cursor {
  
}

class Screen {

public:
  void Write_Text(char text, ); // Writes a Text on a Specific Quadrant



private:
  void setup(); // Creates 4 Quadrands

  ~Screen(); // Deconstructor
}


#endif