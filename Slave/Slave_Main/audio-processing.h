#ifndef AUDIO-PROCESSING
#define AUDIO-PROCESSING

#include <arduinoFFT.h>
#include <defs.h>
#include <types.h>

// For Sampler ===========================================================================
#define SAMPLES 1024
#define SAMPLING_FREQ 40000
#define AMPLITUDE 1000
#define AUDIO_IN_PIN A2


void sampler(); //Gets samples of Audio from port

void FourierFunction(); // Runs FFT on Samples

void audio_analyzer(); // Creates Variables for Audio that are actually Useful


#endif
