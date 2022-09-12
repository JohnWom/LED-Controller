#include "Data_Mangaer.h"



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

  void incrementColorNum() {
    color_num ++;
    if (color_num > num_colors) {
      color_num = 0;
    }
  }
  void decrementColorNum() {
    color_num --;
    if (color_num < 0) {
      color_num = num_colors;
    }
  }

  void incrementMusicPatternNum() {
    music_pattern_num ++;
    if (music_pattern_num > num_mpatterns) {
      music_pattern_num = 0;
    }
  }

  void decrementMusicPatternNum() {
    music_pattern_num --;
    if (music_pattern_num < 0) {
      music_pattern_num = num_mpatterns;
    }
  }

  void incrementStaticPatternNum() {
    static_pattern_num ++;
    if (static_pattern_num > num_spatterns) {
      static_pattern_num = 0;
    }
  }

  void decrementStaticPatternNum() {
    static_pattern_num --;
    if (static_pattern_num < 0) {
      static_pattern_num = num_msatterns;
    }
  }

  void togglePower() {
    power = !power;
  }

  void toggleMusic() {
    music = !music;
  }
};