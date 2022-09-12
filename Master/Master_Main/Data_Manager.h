#ifndef DATA_MANAGER
#define DATA_MANAGER

std::vector

class Data_Manager 
{

private:
  int num_colors;
  int num_mpatterns;
  int num_spatterns;

  int color_num = 0;
  int music_pattern_num = 0;
  int static_pattern_num = 0;
  bool power = true;
  bool music = false;

public:

  void incrementColorNum();   // increments the color number

  void decrementColorNum();   // decrements the color number

  void incrementMusicPatternNum(); // increments the music pattern number

  void decrementMusicPatternNum(); // decrements the music pattern number

  void incrementStaticPatternNum(); // increments the static pattern number

  void decrementStaticPatternNum(); // decrements the static pattern number

  void togglePower();   // toggles power state

  void toggleMusic();   // toggles music state


};

#endif