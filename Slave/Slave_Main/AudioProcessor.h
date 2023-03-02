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

    static void followBeat();

    static void threeBand();

    static void fiveBand();

    static void volume();

    static arduinoFFT FFT;

    static double vReal[SAMPLES];

    static double vImag[SAMPLES];

  private:
  
    static void readAudio();

    static void runFFT();
};

#endif