#ifndef AUDIO_PROCESSOR
#define AUDIO_PROCESSOR

#include <arduinoFFT.h>

#define SAMPLES 1024
#define SAMPLING_FREQ 40000
#define AMPLITUDE 1000
#define AUDIO_IN_PIN A2

class AudioProcessor
{
  public:
    AudioProcessor();

    void followBeat();

    void threeBand();

    void fiveBand();

    void volume();

  private:
    arduinoFFT FFT;
    double vReal[SAMPLES];
    double vImag[SAMPLES];

    void readAudio();

    void runFFT();
};

#endif