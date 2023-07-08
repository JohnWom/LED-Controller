#include "AudioProcessor.h"

AudioProcessor::AudioProcessor()
{
  FFT = arduinoFFT(vReal, vImag, SAMPLES, SAMPLING_FREQ);
}

void AudioProcessor::followBeat()
{
  // Run FFT
  AudioProcessor::readAudio();
  AudioProcessor::runFFT();

  // Pull Bass
}

int* AudioProcessor::threeBand()
{
  AudioProcessor::readAudio();
  AudioProcessor::runFFT();

  // Divide into bins   Bin size ~156 HZ
  int* bins = (int*) calloc(3, sizeof(int));

  for (int i = 0; i < SAMPLES / 2; i++) {
    // Simple Noise Filter
    if (vReal[i] < 200) {
      continue;
    }
    // Bass 20-200Hz
    if (i == 0) {
      bins[0] += AudioProcessor::vReal[i];
    } // Mids 200-2000Hz
    else if (i > 0  && i < 14) {
      bins[1] += AudioProcessor::vReal[i];
    } // Treble >2000Hz
    else {
      bins[2] += AudioProcessor::vReal[i];
    }
  }
  return bins;
}

void AudioProcessor::fiveBand()
{

}

void AudioProcessor::volume()
{

}

int* AudioProcessor::Live() {
  AudioProcessor::readAudio();
  AudioProcessor::runFFT();

  // Divide into bins   Bin size ~156 HZ
  int* bins = (int*) calloc(8, sizeof(int));

    for (int i = 0; i < SAMPLES / 2; i++) {
    // Simple Noise Filter
    if (vReal[i] < 400) {
      continue;
    }
    
    if (i == 0) {
      bins[0] += AudioProcessor::vReal[i];
    } 
    else if (i > 0  && i < 2) {
      bins[1] += AudioProcessor::vReal[i];
    } 
    else if (i >= 2  && i < 3) {
      bins[2] += AudioProcessor::vReal[i];
    } 
    else if (i >= 3  && i < 7) {
      bins[3] += AudioProcessor::vReal[i];
    } 
    else if (i >= 7  && i < 14) {
      bins[4] += AudioProcessor::vReal[i];
    } 
    else if (i >= 14  && i < 28) {
      bins[5] += AudioProcessor::vReal[i];
    } 
    else if (i >= 28  && i < 57) {
      bins[6] += AudioProcessor::vReal[i];
    } 
    else {
      bins[7] += AudioProcessor::vReal[i];
    }
  }

  return bins;
}

void AudioProcessor::readAudio()
{
  unsigned long newTime;
  for (int i = 0; i < SAMPLES; i++){
        newTime=micros();
        vReal[i] = analogRead(AUDIO_IN_PIN);
        vImag[i] = 0;
        while ((micros()-newTime) < 22) {/* Do Nothing */}   // time between samples, 44.1kHz rate
    }
}

void AudioProcessor::runFFT()
{
  FFT.DCRemoval();                                      // Noise Removal Function
  FFT.Windowing(FFT_WIN_TYP_FLT_TOP, FFT_FORWARD);      // Windowing Function
  FFT.Compute(FFT_FORWARD);                             // Performing FFT
  FFT.ComplexToMagnitude();                             // Calculating Magnitudes
}